#ifdef SIMULATION
float sim_get_voltage(void);
float sim_get_current(void);
#endif
float adc_get_voltage(void)
{
#ifdef SIMULATION
    return sim_get_voltage();
#else
    return 0.0f; 
#endif
}

float adc_get_current(void)
{
#ifdef SIMULATION
    return sim_get_current();
#else
    return 0.0f;
#endif
}
