#include <stdint.h>

#ifdef SIMULATION
void sim_timer_tick(uint32_t ms);
uint32_t sim_timer_get_ms(void);
#endif

uint32_t timer_get_ms(void)
{
#ifdef SIMULATION
    return sim_timer_get_ms();
#else
    return 0;
#endif
}

void timer_delay_ms(uint32_t ms)
{
#ifdef SIMULATION
    sim_timer_tick(ms);
#else
    /* Real delay later */
#endif
}
