/*
 * hal_systick.h
 *
 *  Created on: Mar 8, 2020
 *      Author: Loay
 */

#ifndef STM32L4XX_HAL_DRIVER_INC_HAL_SYSTICK_H_
#define STM32L4XX_HAL_DRIVER_INC_HAL_SYSTICK_H_

/*This Header file contain addresses and typedefs of the device registers*/
#include "stm32l432xx.h"
/*Standard integers*/
#include "stdint.h"

extern  uint32_t SystemCoreClock ;


uint32_t HAL_SysTick_Config(uint32_t ticks) ;

void HAL_SysTick_init(void) ;
void delay_ms(uint32_t ms) ;



#endif /* STM32L4XX_HAL_DRIVER_INC_HAL_SYSTICK_H_ */
