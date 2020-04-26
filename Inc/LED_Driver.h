/*
 * LED_Driver.h
 *
 *  Created on: Feb 25, 2020
 *      Author: Loay
 */

#ifndef STM32L4XX_HAL_DRIVER_INC_LED_DRIVER_H_
#define STM32L4XX_HAL_DRIVER_INC_LED_DRIVER_H_

#include "hal_gpio.h"

void LED_on(void);
void LED_off(void);
void LED_toggle(void);
void LED_init(void);

#endif /* STM32L4XX_HAL_DRIVER_INC_LED_DRIVER_H_ */
