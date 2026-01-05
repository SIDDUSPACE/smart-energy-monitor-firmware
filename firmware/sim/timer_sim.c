#include <stdint.h>
static uint32_t sim_time_ms = 0;
void sim_timer_tick(uint32_t ms)
{
    sim_time_ms += ms;
}
uint32_t sim_timer_get_ms(void)
{
    return sim_time_ms;
}
