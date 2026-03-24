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
