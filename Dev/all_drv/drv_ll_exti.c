/**
 ******************************************************************************
 * @file           : drv_ll_exti.c
 * @author         : Paul Rojas
 * @brief          : [EXTI] EXTI and syscfg controller driver
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
#include "drv_ll_exti.h"

#define EXTI0_RTSR_TRIGG (1 << 0)
#define EXTI0_IMR_MASK   (1 << 0)

#define SYSCFG_RCC_APB2ENR (1 << 14)
#define SYSCFG_EXTICR1_EXTI0_PA0 (0 << 0)
#define SYSCFG_EXTICR1_EXTI0_CLR (7 << 0)

void EXTI0_init_driver(void)
{
    /* EXTI0 line: HW Interrupt context, 
     - Trigger in edge detection: RTSR = 1 (rising edge)
     - Interrupt request enabled: IMR = 1 
     - When the selected edge occurs in the interrupt line:
       * Interrupt request is generated (NVIC_IRQ channel mapped to the EXTI controller)*/
    EXTI->RTSR |= EXTI0_RTSR_TRIGG;
    EXTI->IMR  |= EXTI0_IMR_MASK;

    /* Syscfg controller: manage external interrupt line connection to GPIO
        - Enable CLK peripheral for SYSCFG
        - EXTI0 line is connected to PA0 */
    RCC->APB2ENR |= SYSCFG_RCC_APB2ENR; 
    SYSCFG->EXTICR[0] &= ~SYSCFG_EXTICR1_EXTI0_CLR;
    SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI0_PA0; 
}
