/**
 ******************************************************************************
 * @file           : drv_ll_uart.c
 * @author         : Paul Rojas
 * @brief          : [UART] UART driver configuration
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
*/

#include "stm32f4xx.h"
#include "drv_ll_uart.h"

#define UART4_APB1ENR       (1 << 19)
#define UART4_RX_EN         (1 << 2)
#define UART4_TX_EN         (1 << 3)
#define UART4_PERIPHERAL_EN (1 << 13)



void UART_init_driver(void)
{
    /* driver config GPIO phase:
        - RCC GPIOA CLK EN
        - UART TX/RX pins as alternate function: AF8-PA1-RX(UART4) / AF8-PA0-TX(UART4)
        - PA0 / PA1 AF GPIO mode  */
    RCC->AHB1ENR  |= (1 << 0);
    GPIOA->AFR[0] |= (0b1000 << 0);
    GPIOA->MODER  |= (0b10 << 0);
    GPIOA->AFR[0] |= (0b1000 << 4);
    GPIOA->MODER  |= (0b10 << 2);
    GPIOA->OSPEEDR |= 0x0000000A;

    /* driver config UART phase:
        - RCC UART4/5 CLK EN
        - ENABLE UART Periph: RX / TX
        - BAUD RATE CONFIG : Fclk / 16 * 115200:
            fractional part = 13
            mantissa = 22 */
    RCC->APB1ENR |= UART4_APB1ENR;
    UART4->CR1   |= UART4_RX_EN | UART4_TX_EN | UART4_PERIPHERAL_EN;
    UART4->BRR   |= (22 << 4) | (13 << 0);
}