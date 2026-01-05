#include <math.h>
#ifndef PI
#define PI 3.14159265358979323846f
#endif

/* Simulation time base */
static float sim_time = 0.0f;
static const float sim_dt = 0.001f; /* 1 ms */

/* Electrical parameters */
#define AC_FREQ_HZ 50.0f
#define V_PEAK     325.0f
#define I_PEAK     10.0f

float sim_get_voltage(void)
{
    float voltage = V_PEAK *sinf(2.0f * PI * AC_FREQ_HZ * sim_time)
;
    sim_time += sim_dt;
    return voltage;
}

float sim_get_current(void)
{
    if (sim_time > 5.0f){
        return 12.0f * sinf(2.0f * PI * AC_FREQ_HZ * sim_time);
    }
    return I_PEAK * sinf(2.0f * PI * AC_FREQ_HZ * sim_time);
}
