/**
 ******************************************************************************
 * @file           : drv_ll_systick.c
 * @author         : Paul Rojas
 * @brief          : [SysTick] SysTick timer methods implementation
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

/*  SYSTICK_ENABLE = Enable the counter
    SYSTICK ClockSource = Selects system or external clock source 
    SYSTICK Countflag = SW can use this bit state to determine if SysTick has ever counted to zero  */

#define SYSTICK_CSR_ENABLE    (1 << 0)
#define SYSTICK_CSR_CLOCKSRC  (1 << 2)
#define SYSTICK_CSR_COUNTFLAG (1 << 16) 
#define SYSTICK_CYCLES_PER_MS (16000u) 

/* SysTick drv config:
        - Write Reload value: number of cycles for each ms delay 
        - Clear current value / CountFlag CSR reg
        - Set CSR register: When Enable = 1, counter takes Reload value */

void SysTick_init_driver(void)
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
 