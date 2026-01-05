#include <stdio.h>
#include <stdbool.h>

#include "adc_if.h"
#include "gpio_if.h"
#include "timer_if.h"
#include "comm_if.h"

#include "energy_manager.h"
#include "load_controller.h"
#include "fault_manager.h"
#include "system_state.h"

int main(void)
{
    /* Initialize system modules */
    system_state_init();
    energy_manager_init();
    load_controller_init();
    fault_manager_init();

    while (1)
    {
        /* Acquire raw samples */
        float voltage = adc_get_voltage();
        float current = adc_get_current();

        /* Feed samples to energy manager */
        energy_manager_update(voltage, current);

        /* ---- CRITICAL FIX ----
           Run protection logic ONLY when a NEW RMS value is ready */
        if (energy_manager_is_rms_updated())
        {
            float current_rms = energy_manager_get_current_rms();

            /* Evaluate overload protection */
            load_controller_update(current_rms);

            /* Clear RMS flag after consuming */
            energy_manager_clear_rms_flag();
        }

        /* ---- FINAL RELAY AUTHORITY ----
           Fault manager has absolute priority */
        if (fault_manager_is_active())
        {
            gpio_set_relay(false);
        }
        else
        {
            gpio_set_relay(load_controller_is_relay_on());
        }

        /* Publish telemetry */
        comm_publish_metrics(
            energy_manager_get_voltage_rms(),
            energy_manager_get_current_rms(),
            energy_manager_get_energy_wh()
        );

        /* Control loop timing */
        timer_delay_ms(500);
    }

    /* Embedded firmware never exits */
    return 0;
}
