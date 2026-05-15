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

void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk,  uint32_t BaudRate);

void UART4_init_driver(void)
{
    /* driver config GPIO phase:
        - RCC GPIOA CLK EN
        - UART TX/RX pins as alternate function: AF8-PA1-RX(UART4) / AF8-PA0-TX(UART4)
        - PA0 / PA1 AF GPIO mode  */
    RCC->AHB1ENR  |= (1 << 0);
    
    // RESET PIN MODES & SET THEM TO AF MODE

    GPIOA->MODER &= ~((3 << 0) | (3 << 2));
    GPIOA->MODER |= (2 << 0) | (2 << 2);
    GPIOA->OSPEEDR |= 0x0000000A;

    // RESET AF & SET THE AF: AFRL1[3:0]/ RX &  AFRL0[3:0] / TX 

    GPIOA->AFR[0] &= ~((15 << 0) | (15 << 4));
    GPIOA->AFR[0] |= (8 << 0) | (8 << 4);
    
    /* driver config UART phase:
        - RCC UART4/5 CLK EN
        - ENABLE UART Periph: RX / TX
        - BAUD RATE CONFIG : Fclk / 16 * 115200:
            fractional part = 13
            mantissa = 22 */
    RCC->APB1ENR |= (1 << 19);
    UART4->CR1   |= (1 << 3) | (1 << 2) | (1 << 13);
    //UART4->BRR   |= (22 << 4);
    //UART4->BRR   |= 13;
    uart_set_baudrate(UART4, 42000000, 115200);
}

void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk,  uint32_t BaudRate)
{
	// BRR = clock frequency / BaudRate
	uint16_t brr_value = ((PeriphClk + (BaudRate/2U))/BaudRate);

	//  (BaudRate/2U))/BaudRate) simplifies to 1/2 and increase accuracy when rounding in this case 
	USARTx->BRR = brr_value;
}

void UART4_write(uint8_t uart4_char)
{
    
	/* If TXE flag is set, write data byte to DR */
	while(!(UART4->SR & (1 << 6)));
	UART4->DR = (uart4_char & 0xFF);
}

uint8_t UART4_read(void)
{
    /* When a character is received, wait until RXNE flag is set, then read data */
	while(!(UART4->SR & (1 << 5)));
	
    return UART4->DR; /* 0xFF & DATA_RX */ 
}