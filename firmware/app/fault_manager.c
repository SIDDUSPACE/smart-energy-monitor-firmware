#include <stdbool.h>

static bool fault_active = false;

void fault_manager_init(void)
{
    fault_active = false;
}

void fault_manager_set_fault(void)
{
    fault_active = true;
}

bool fault_manager_is_active(void)
{
    return fault_active;
}
