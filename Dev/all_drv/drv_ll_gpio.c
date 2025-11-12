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

/* Local methods declaration */

void GPIO_init_driver(void);

/* global objects */

volatile uint8_t tx_buffer[] = {"Hola"}; // here we send a message from UART pin
volatile uint8_t rx_buffer[] = {"TLS"}; // message to be received through UART pin 

 /* Jump into main applicative SW */

 int main(void)
 {  
    GPIO_init_driver();
    SysTick_init_driver();
    EXTI0_init_driver();
    UART_init_driver();

    /*   PLACEHOLDER: EXTI NVIC configuration and call
        - Set priority: 0, is the highest
        - Enable interrupt
        - Invoke: void EXTI0_NVIC_call(); */

     /* Loop */
     while(1)
     {  
        for(int i =0; i < sizeof(tx_buffer); i++)
        {
            UART4->DR = tx_buffer[i];
            while(!(UART4->SR & (1 << 7)));
        }

        for(int j= 0; j < sizeof(rx_buffer); j++)
        {
            UART4->DR = rx_buffer[j];
            while(!(UART4->SR & (1 << 5)));
        }
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