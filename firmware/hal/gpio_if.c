#include <stdbool.h>

#ifdef SIMULATION
void sim_set_relay(bool state);
#endif

void gpio_set_relay(bool state)
{
#ifdef SIMULATION
    sim_set_relay(state);
#else
    /* Real GPIO implementation later */
#endif
}
