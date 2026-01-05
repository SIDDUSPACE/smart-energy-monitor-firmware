#include <stdbool.h>
#ifndef ENERGY_MANAGER_H
#define ENERGY_MANAGER_H
void energy_manager_init(void);
void energy_manager_update(float voltage, float current);
float energy_manager_get_energy_wh(void);
float energy_manager_get_current_rms(void);
float energy_manager_get_voltage_rms(void);
bool energy_manager_is_rms_updated(void);
void energy_manager_clear_rms_flag(void);

#endif
