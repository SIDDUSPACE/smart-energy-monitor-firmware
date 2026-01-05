#ifndef TIMER_IF_H
#define TIMER_IF_H
#include <stdint.h>
uint32_t timer_get_ms(void);
void timer_delay_ms(uint32_t ms);

#endif
