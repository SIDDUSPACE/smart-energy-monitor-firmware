#include <stdio.h>
#include <stdbool.h>

static bool simulated_relay_state = true;

void sim_set_relay(bool state)
{
    if (simulated_relay_state != state)
    {
        printf("[SIM] RELAY %s\n", state ? "ON" : "OFF");
    }
    simulated_relay_state = state;
}
