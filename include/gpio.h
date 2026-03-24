#ifndef GPIO_H
#define GPIO_H

#include <stdbool.h>
#include <stdint.h>

#include "stm32f411xx.h"

typedef enum {
  GPIO_MODE_INPUT = 0U,
  GPIO_MODE_OUTPUT = 1U,
  GPIO_MODE_ALT = 2U,
  GPIO_MODE_ANALOG = 3U
} gpio_mode_t;

typedef enum {
  GPIO_OTYPE_PUSHPULL = 0U,
  GPIO_OTYPE_OPENDRAIN = 1U
} gpio_otype_t;

typedef enum {
  GPIO_SPEED_LOW = 0U,
  GPIO_SPEED_MEDIUM = 1U,
  GPIO_SPEED_FAST = 2U,
  GPIO_SPEED_HIGH = 3U
} gpio_speed_t;

typedef enum {
  GPIO_NOPULL = 0U,
  GPIO_PULLUP = 1U,
  GPIO_PULLDOWN = 2U
} gpio_pull_t;

typedef struct {
  gpio_mode_t mode;
  gpio_otype_t otype;
  gpio_speed_t speed;
  gpio_pull_t pull;
} gpio_config_t;

void gpio_init(GPIO_TypeDef *port, uint8_t pin, const gpio_config_t *cfg);
void gpio_write(GPIO_TypeDef *port, uint8_t pin, bool level_high);
void gpio_toggle(GPIO_TypeDef *port, uint8_t pin);
bool gpio_read(GPIO_TypeDef *port, uint8_t pin);

#endif /* GPIO_H */
