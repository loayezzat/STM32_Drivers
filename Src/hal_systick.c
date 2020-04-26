/*
 * hal_systick.c
 *
 *  Created on: Mar 8, 2020
 *      Author: Loay
 */
#include "hal_systick.h"

volatile static uint32_t count = 0 ;
/*ISR*/
void SysTick_Handler (void)
{
	count ++ ;
}

uint32_t HAL_SysTick_Config(uint32_t ticks)
{
  if ((ticks - 1UL) > SysTick_LOAD_RELOAD_Msk)
  {
    return (1UL);                                                   /* Reload value impossible */
  }

  SysTick->LOAD  = (uint32_t)(ticks - 1UL);                         /* set reload register */
  NVIC_SetPriority (SysTick_IRQn, (1UL << __NVIC_PRIO_BITS) - 1UL); /* set Priority for Systick Interrupt */
  SysTick->VAL   = 0UL;                                             /* Load the SysTick Counter Value */
  SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |
                   SysTick_CTRL_TICKINT_Msk   |
                   SysTick_CTRL_ENABLE_Msk;                         /* Enable SysTick IRQ and SysTick Timer */
  return (0UL);                                                     /* Function successful */
}

void HAL_SysTick_init(void)
{
	HAL_SysTick_Config(SystemCoreClock /1000) ;
}
void delay_ms(uint32_t time)
{

	uint32_t start = count ;
	while ((count- start) < time ) ; /*wait until reaches the value */
	return ;
}
