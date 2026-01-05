#include <stdbool.h>
#include "load_controller.h"
#include "fault_manager.h"
/* Configuration */
#define OVERCURRENT_RMS_THRESHOLD  8.0f   /* Amps */
#define OVERLOAD_CYCLES_LIMIT     2

static int overload_count = 0;
static bool relay_state = true;   /* true = ON */
static bool tripped = false;      /* latch */

void load_controller_init(void)
{
    overload_count = 0;
    relay_state = true;
    tripped = false;
}

void load_controller_update(float current_rms)
{
    if (tripped)
        return;   /* latch: once tripped, stay OFF */

    if (current_rms > OVERCURRENT_RMS_THRESHOLD)
    {
        overload_count++;
    }
    else
    {
        overload_count = 0;
    }

    if (overload_count >= OVERLOAD_CYCLES_LIMIT)
    {
        relay_state = false;
        tripped = true;
        fault_manager_set_fault();
    }
}

bool load_controller_is_relay_on(void)
{
    return relay_state;
}
