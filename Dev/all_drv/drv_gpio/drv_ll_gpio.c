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
 
  /* Jump into main applicative SW */

 int main(void)
 {
    
     /* - Enable  CLK Peripheral for GPIO: AHB1ENR
        - Configure Mode: I/O, GPIOD here as output for led blink */
      
     RCC->AHB1ENR |= (1<<3);
     GPIOD->MODER |= (1<<(13*2)) | (1<<(12*2)); 
    
     /* Loop */

     while(1)
     {
         for(int i=0;i<1000000;i++); /* Mock delay: instruction's cycles */
         GPIOD->ODR ^= (1<<12); /* Write value: Toogle LED */
         for(int i=0;i<1000000;i++);
         GPIOD->ODR ^= (1<<13);
     }
 }
 