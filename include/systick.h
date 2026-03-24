#ifndef SYSTICK_H
#define SYSTICK_H

#include <stdint.h>

void systick_init_1khz(uint32_t core_hz);
void systick_delay_ms(uint32_t ms);

#endif /* SYSTICK_H */
