/**
 ******************************************************************************
 * @file           : drv_ll_gpio.c
 * @author         : Paul Rojas
 * @brief          : [GPIO] Toggle LED example
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

 /* SYSTICK_ENABLE = Enable the counter
    SYSTICK Countflag = SW can use this bit state to determine if SysTick has ever counted to zero 
    SYSTICK ClockSource = Selects system or external clock source  */

 #define SYSTICK_CSR_ENABLE    (1 << 0)
 #define SYSTICK_CSR_CLOCKSRC  (1 << 2)
 #define SYSTICK_CSR_COUNTFLAG (1 << 16) 
 #define SYSTICK_CYCLES_PER_MS (16000u) 

 /* Local prototypes */
 void SysTick_DelayMs(uint32_t delay_ms);
 void SysTick_Init(void);

/* Jump into main applicative SW */

 int main(void)
 {
    
     /* GPIO peripheral drv config: 
        - Enable  CLK Peripheral for GPIOD and GPIOA: AHB1ENR
        - Configure Port Mode: I/O, GPIOD here as output for led blink 
        - User Push button PA0 = GPIOA reset state is equal to be in Input mode */
      
     RCC->AHB1ENR |= (1 << 0) | (1 << 3);
     GPIOD->MODER |= (1 << (15 * 2)) | (1 <<(12 * 2));
    
     /* SysTick drv config:
        - Write Reload value: number of cycles for each ms delay 
        - Clear current value / CountFlag CSR reg
        - Set CSR register: When Enable = 1, counter takes Reload value */

    SysTick_Init();

     /* Loop */

     while(1)
     {
         SysTick_DelayMs(1000u);
         GPIOD->ODR ^= (1<<12);
         SysTick_DelayMs(1000u);
         GPIOD->ODR ^= (1<<15);
     }
}

/* Local method's implementation */

void SysTick_Init(void)
{
    SysTick->LOAD = SYSTICK_CYCLES_PER_MS - 1; 
    SysTick->VAL  = 0;
    SysTick->CTRL |= SYSTICK_CSR_ENABLE | SYSTICK_CSR_CLOCKSRC;
}

void SysTick_DelayMs(uint32_t delay_ms)
{
    while(delay_ms)
    {
        if(SysTick->CTRL & SYSTICK_CSR_COUNTFLAG)
        {
            delay_ms--;
        }
    }
}
 