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

volatile uint8_t txbuffer[] = "UART4 Tx working...\n";
void GPIO_init_driver(void);

/* global objects */

 /* Jump into main applicative SW */

 int main(void)
 {  
    GPIO_init_driver();
    SysTick_init_driver();
    //EXTI0_init_driver();
    set_sysclk_to_168();
    //UART_init_driver();

    /*   PLACEHOLDER: EXTI NVIC configuration and call
        - Set priority: 0, is the highest
        - Enable interrupt
        - Invoke: void EXTI0_NVIC_call(); */
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
    UART4->BRR   |= (22 << 4);
    UART4->BRR   |= 13;

     /* Loop */
     while(1)
     {  
		for(uint32_t i =0; i<sizeof(txbuffer);i++)
		{
			UART4->DR = txbuffer[i];
			while(!(UART4->SR & (1 << 6)));
	 	}
		SysTick_DelayMs(1000);
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