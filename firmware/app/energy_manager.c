#include <math.h>
#include <stdbool.h>
#include "energy_manager.h"

#define SAMPLE_COUNT       100
#define SAMPLE_PERIOD_SEC  0.001f   /* 1 ms */

static float voltage_samples[SAMPLE_COUNT];
static float current_samples[SAMPLE_COUNT];
static int sample_index = 0;

static float energy_wh = 0.0f;
static float last_v_rms = 0.0f;
static float last_i_rms = 0.0f;

/* RMS update flag */
static bool rms_updated = false;

void energy_manager_init(void)
{
    sample_index = 0;
    energy_wh = 0.0f;
    last_v_rms = 0.0f;
    last_i_rms = 0.0f;
    rms_updated = false;
}

void energy_manager_update(float voltage, float current)
{
    voltage_samples[sample_index] = voltage;
    current_samples[sample_index] = current;
    sample_index++;

    if (sample_index >= SAMPLE_COUNT)
    {
        float v_sq_sum = 0.0f;
        float i_sq_sum = 0.0f;
        float p_sum   = 0.0f;

        for (int i = 0; i < SAMPLE_COUNT; i++)
        {
            v_sq_sum += voltage_samples[i] * voltage_samples[i];
            i_sq_sum += current_samples[i] * current_samples[i];
            p_sum    += voltage_samples[i] * current_samples[i];
        }

        last_v_rms = sqrtf(v_sq_sum / SAMPLE_COUNT);
        last_i_rms = sqrtf(i_sq_sum / SAMPLE_COUNT);

        float real_power = p_sum / SAMPLE_COUNT;

        energy_wh += (real_power * SAMPLE_PERIOD_SEC * SAMPLE_COUNT) / 3600.0f;

        sample_index = 0;

        /* Signal that a NEW RMS value is available */
        rms_updated = true;
    }
}

float energy_manager_get_energy_wh(void)
{
    return energy_wh;
}

float energy_manager_get_current_rms(void)
{
    return last_i_rms;
}

float energy_manager_get_voltage_rms(void)
{
    return last_v_rms;
}

/* ---- RMS synchronization helpers ---- */

bool energy_manager_is_rms_updated(void)
{
    return rms_updated;
}

void energy_manager_clear_rms_flag(void)
{
    rms_updated = false;
}
