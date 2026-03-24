#ifndef BSP_LED_H
#define BSP_LED_H

typedef enum {
  BSP_LED_GREEN = 0,
  BSP_LED_ORANGE = 1
} bsp_led_t;

void bsp_led_init(void);
void bsp_led_toggle(bsp_led_t led);

#endif /* BSP_LED_H */
