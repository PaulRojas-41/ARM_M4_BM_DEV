/**
 ******************************************************************************
 * @file           : drv_ll_gpio.c
 * @author         : Paul Rojas
 * @brief          : [GPIO] EXTI interrupt example
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
#include "system_stm32f4xx.h"
#include "drv_ll_systick.h"
#include "drv_ll_exti.h"
#include "drv_ll_uart.h"

#define GPIOA_RCC_AHB1ENR (1 << 0)
#define GPIOD_RCC_AHB1ENR (1 << 3)

#define GPIO_MODE_OUTPUT (1)

#define GPIOD_BLUE_LED_PosD15  (15 *2)
#define GPIOD_GREEN_LED_PosD12 (12 *2)

#define GPIOD_OUT_GREEN_LED (1 << 12)
#define GPIOD_OUT_BLUE_LED  (1 << 15)

#define EXTI0_EDGE_DETECTED (1 << 0)

#define HSI_VALUE    ((uint32_t)16000000U) // Internal high speed oscillator
#define HSE_VALUE    ((uint32_t)8000000U)  // External high speed oscillator
#define LSI_VALUE    ((uint32_t)32000U)    // Internal low speed oscillator
#define LSE_VALUE    ((uint32_t)32768U)    // External low speed oscillator

// Main PLL = N * (source_clock / M) / P
// HSE = 8 Mhz
// fCLK =   N * (8Mhz / M) / P
#define PLL_M   8
#define PLL_Q   7
#define PLL_P   2
#define PLL_N   336

/* Local methods declaration */

void GPIO_init_driver(void);

/* global objects */
uint8_t tx_buffer[5];
uint8_t rx_buffer[4];

 /* Jump into main applicatif SW */

 int main(void)
 {  
    GPIO_init_driver();
    SysTick_init_driver();
    //EXTI0_init_driver();
    set_sysclk_to_168();
    UART4_init_driver();

     /* Loop */
     while(1)
     {  
		for(uint8_t i= 0; i < sizeof(rx_buffer); i++)
		{
			/* When a character is received, wait until RXNE flag is set, then read data */
			while(!(UART4->SR & (1 << 5)));
			rx_buffer[i] = UART4->DR; /* 0xFF & DATA_RX */ 
		}

		for(uint8_t j = 0; j < sizeof(rx_buffer); j++)
		{
			/* If TXE flag is set, write data byte to DR */
			while(!(UART4->SR & (1 << 6)));
	 		UART4->DR = (rx_buffer[j] & 0xFF);
		}

		SysTick_DelayMs(4);
     }
}

/* Local mehthod's definition */

void GPIO_init_driver(void)
{
    /* GPIO peripheral drv config: 
     - Enable  CLK Peripheral for GPIOD and GPIOA: AHB1ENR
     - Configure Port Mode: I/O, GPIOD here as output for led blink 
     - User Push button PA0 = GPIOA reset state is equal to be in Input mode */

    RCC->AHB1ENR |= GPIOA_RCC_AHB1ENR | GPIOD_RCC_AHB1ENR;
    GPIOD->MODER |= (GPIO_MODE_OUTPUT << GPIOD_BLUE_LED_PosD15) | (GPIO_MODE_OUTPUT << GPIOD_GREEN_LED_PosD12);
}
/* EXTI0 IRQ Handler definition */

void EXTI0_IRQHandler(void)
{
    /*  - Check PR bit: if selected edge event (rising in our case) happened
        - Turn ON green led 
        - Clear again PR: otherwise remains set as if the interrupt stills occurring */
    if((EXTI->PR & EXTI0_EDGE_DETECTED))
    {
        GPIOD->ODR |= GPIOD_OUT_GREEN_LED; 
        EXTI->PR |= EXTI0_EDGE_DETECTED;
    }
}