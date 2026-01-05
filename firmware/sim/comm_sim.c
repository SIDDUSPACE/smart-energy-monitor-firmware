#include <stdio.h>
void sim_publish_metrics(float v_rms, float i_rms, float energy_wh)
{
    /* Simulation sink: visible output */
    printf("[SIM] Vrms=%.2f V, Irms=%.2f A, Energy=%.3f Wh\n",
           v_rms, i_rms, energy_wh);
}
