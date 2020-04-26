/*
 * LED_Driver.c
 *
 *  Created on: Feb 25, 2020
 *      Author: Loay
 */
#include "LED_Driver.h"


void LED_init(void)
{
	HAL_GPIOB_CLK_ENABLE()  ;
	GPIO_InitPinTypeDef LED_pin ;
	LED_pin.Pin = 3   ;
	LED_pin.Mode = GPIO_PIN_MODE_OUTPUT ;
	LED_pin.Op_type = GPIO_PIN_OP_TYPE_PP ;
	LED_pin.Pull = GPIO_PIN_NO_PULL;
	LED_pin.Speed = GPIO_PIN_OP_SPEED_MEDIUM ;
	LED_pin.Alternate = 0x00 ; //value doesn't affect
	HAL_GPIO_init(GPIOB , &LED_pin) ;

}

void LED_on(void)
{
	HAL_GPIO_SET_PIN(GPIOB , 3) ;
}
void LED_off(void)
{
	HAL_GPIO_CLEAR_PIN(GPIOB , 3) ;
}
void LED_toggle(void)
{
	HAL_GPIO_TOGGLE_PIN(GPIOB , 3) ;
}
