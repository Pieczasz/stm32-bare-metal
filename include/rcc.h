#ifndef RCC_H
#define RCC_H

#include <stdbool.h>
#include <stdint.h>

typedef enum {
  RCC_GPIO_PORT_A = 0U,
  RCC_GPIO_PORT_B = 1U,
  RCC_GPIO_PORT_C = 2U,
  RCC_GPIO_PORT_D = 3U,
  RCC_GPIO_PORT_E = 4U,
  RCC_GPIO_PORT_H = 7U
} rcc_gpio_port_t;

void rcc_enable_gpio_clock(rcc_gpio_port_t port);
bool rcc_set_sysclk_84mhz_hse(uint32_t hse_hz);
uint32_t rcc_get_sysclk_hz(void);

#endif /* RCC_H */
