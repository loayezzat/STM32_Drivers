/*
 * exti.c
 *
 *  Created on: Mar 7, 2020
 *      Author: Loay
 */
#include "hal_exti.h"
#include "hal_systick.h"
void HAL_EXTI_init(void)
{
	/*Enabling SYSCFG module clk*/
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN ;
	/*Mapping PA0 to EXTI0*/
	SYSCFG->EXTICR[0] = SYSCFG->EXTICR[0] & ~(0x0F) ;
	EXTI->FTSR1 |= EXTI_FTSR1_FT0 ;
	EXTI->RTSR1 &= ~(EXTI_FTSR1_FT0);
	EXTI->IMR1  |= EXTI_IMR1_IM0 ;

}

void EXTI0_IRQHandler (void)
{

	LED_toggle() ;
	delay_ms(500);
	LED_toggle() ;
	delay_ms(500);
	LED_toggle() ;
	delay_ms(500);
	LED_toggle() ;
	delay_ms(500);
	//EXTI->PR1 |= EXTI_PR1_PIF0 ; /*Clear Pending Bit*/

}
