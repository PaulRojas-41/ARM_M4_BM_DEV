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

 /* Jump into main applicative SW */

 int main(void)
 {  
    GPIO_init_driver();
    SysTick_init_driver();
    EXTI0_init_driver();

    /* NVIC configuration:
        - Set priority: 0, is the highest
        - Enable interrupt */
    NVIC_SetPriority(EXTI0_IRQn, 0);
    NVIC_EnableIRQ(EXTI0_IRQn);
    

     /* Loop */
     while(1)
     {
         SysTick_DelayMs(1000u);
         GPIOD->ODR ^= GPIOD_OUT_BLUE_LED;

         if(GPIOD->ODR & GPIOD_OUT_GREEN_LED)
         {
            SysTick_DelayMs(500u);
            GPIOD->ODR &= ~GPIOD_OUT_GREEN_LED;
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