#include <stdint.h>

#define RCC_BASE 0x40023800UL
#define GPIOD_BASE 0x40020C00UL

#define RCC_AHB1ENR (*(volatile uint32_t *)(RCC_BASE + 0x30U))
#define GPIOD_MODER (*(volatile uint32_t *)(GPIOD_BASE + 0x00U))
#define GPIOD_ODR (*(volatile uint32_t *)(GPIOD_BASE + 0x14U))

#define RCC_AHB1ENR_GPIODEN (1U << 3)
#define LD4_PIN 12U
#define LD3_PIN 13U

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
}

// Startup code
__attribute__((noreturn)) void Reset_Handler(void) {
  extern long _sbss, _ebss, _sdata, _edata, _sidata;

  for (long *dst = &_sbss; dst < &_ebss; dst++)
    *dst = 0;

  for (long *dst = &_sdata, *src = &_sidata; dst < &_edata;)
    *dst++ = *src++;

  main();

  // The code should never get here
  for (;;)
    (void)0;
}

extern uint32_t _estack; // Defined in f411.ld

// 16 standard and 91 STM-32 specific handlers
__attribute__((section(".isr_vector"))) void (*const tab[16 + 91])(void) = {
    (void (*)(void))(&_estack), Reset_Handler};
