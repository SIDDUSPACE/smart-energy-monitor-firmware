#ifdef SIMULATION
void sim_publish_metrics(float v, float i, float e);
#endif

void comm_publish_metrics(float v_rms, float i_rms, float energy_wh)
{
#ifdef SIMULATION
    sim_publish_metrics(v_rms, i_rms, energy_wh);
#else
    /* Real communication later */
#endif
}
