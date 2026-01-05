#ifndef FAULT_MANAGER_H
#define FAULT_MANAGER_H
#include <stdbool.h>
void fault_manager_init(void);
void fault_manager_update(void);
void fault_manager_raise(void);
void fault_manager_clear(void);

void fault_manager_set_fault(void);
bool fault_manager_is_active(void);
#endif
