#ifndef LOAD_CONTROLLER_H
#define LOAD_CONTROLLER_H
#include <stdbool.h>
void load_controller_init(void);
void load_controller_update(float current_rms);
bool load_controller_is_relay_on(void);

#endif
