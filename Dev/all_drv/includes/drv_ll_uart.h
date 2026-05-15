#ifndef drv_ll_uart_h
#define drv_ll_uart_h

#include "stm32f4xx.h"
/* global methods */
void SysTick_init_driver(void);
extern void UART4_init_driver(void);
void UART4_write(uint8_t uart4_char);
uint8_t UART4_read(void);

#endif // DRV_LL_SYSTICK_H