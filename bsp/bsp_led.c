#include "bsp_led.h"

#include "gpio.h"
#include "rcc.h"

#define BSP_LED_GREEN_PIN 12U
#define BSP_LED_ORANGE_PIN 13U

void bsp_led_init(void) {
  const gpio_config_t cfg = {
      .mode = GPIO_MODE_OUTPUT,
      .otype = GPIO_OTYPE_PUSHPULL,
      .speed = GPIO_SPEED_LOW,
      .pull = GPIO_NOPULL,
  };

  rcc_enable_gpio_clock(RCC_GPIO_PORT_D);
  gpio_init(GPIOD, BSP_LED_GREEN_PIN, &cfg);
  gpio_init(GPIOD, BSP_LED_ORANGE_PIN, &cfg);
}

void bsp_led_toggle(bsp_led_t led) {
  if (led == BSP_LED_GREEN) {
    gpio_toggle(GPIOD, BSP_LED_GREEN_PIN);
  } else {
    gpio_toggle(GPIOD, BSP_LED_ORANGE_PIN);
  }
}
