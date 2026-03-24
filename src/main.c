#include "gpio.h"

static void delay(volatile uint32_t cycles) {
  while (cycles--) {
    __asm volatile("nop");
  }
}

int main(void) {
  RCC_AHB1ENR |= RCC_AHB1ENR_GPIODEN;

  GPIOD_MODER &= ~(3U << (LD4_PIN * 2U));
  GPIOD_MODER |= (1U << (LD4_PIN * 2U));

  GPIOD_MODER &= ~(3U << (LD3_PIN * 2U));
  GPIOD_MODER |= (1U << (LD3_PIN * 2U));

  for (;;) {
    GPIOD_ODR ^= (1U << LD4_PIN);
    GPIOD_ODR ^= (1U << LD3_PIN);
    delay(1600000U);
  }

  return 1;
}