/*
 * gpio.h
 *
 *  Created on: Feb 24, 2020
 *      Author: Loay
 */

#ifndef STM32L4XX_HAL_DRIVER_INC_HAL_GPIO_H_
#define STM32L4XX_HAL_DRIVER_INC_HAL_GPIO_H_

/*This Header file contain addresses and typedefs of the device registers*/
#include "stm32l432xx.h"
/*Standard integers*/
#include "stdint.h"



#define HAL_GPIOA_CLK_ENABLE()  (RCC->AHB2ENR |= (uint32_t )0x00000001U)
#define HAL_GPIOB_CLK_ENABLE()  (RCC->AHB2ENR |= (uint32_t )0x00000002U)
#define HAL_GPIOC_CLK_ENABLE()  (RCC->AHB2ENR |= (uint32_t )0x00000004U)
#define HAL_GPIOD_CLK_ENABLE()  (RCC->AHB2ENR |= (uint32_t )0x00000008U)
#define HAL_GPIOE_CLK_ENABLE()  (RCC->AHB2ENR |= (uint32_t )0x00000010U)
#define HAL_GPIOH_CLK_ENABLE()  (RCC->AHB2ENR |= (uint32_t )0x00000080U)

#define HAL_GPIO_SET_PIN(GPIOX , PIN)  		((GPIOX)->BSRR |= (1<<(PIN)))
#define HAL_GPIO_CLEAR_PIN(GPIOX , PIN) 	((GPIOX)->BRR  |= (1<<(PIN)))
#define HAL_GPIO_TOGGLE_PIN(GPIOX , PIN)  	((GPIOX)->ODR  ^= (1<<(PIN)))
#define HAL_GPIO_READ_PIN(GPIOX , PIN) 		(((GPIOX)->IDR)>>(PIN) & 0x00000001)


/*
#define GPIO_MODE_INPUT		0x0000
//Input Floating Mode
#define GPIO_MODE_OUTPUT_PP 0x1001
// Output Push Pull Mode
#define GPIO_MODE_OUTPUT_OD 0x1001
// Output Open Drain Mode
#define GPIO_MODE_AF_PP
// Alternate Function Push Pull Mode
#define GPIO_MODE_AF_OD
// Alternate Function Open Drain Mode
#define GPIO_MODE_ANALOG
// Analog Mode
#define GPIO_MODE_IT_RISING
// External Interrupt Mode with Rising edge trigger detection
#define GPIO_MODE_IT_FALLING
// External Interrupt Mode with Falling edge trigger detection
#define GPIO_MODE_IT_RISING
//_FALLING External Interrupt Mode with Rising/Falling edge trigger detection
#define GPIO_MODE_EVT_RISING
// External Event Mode with Rising edge trigger detection
#define GPIO_MODE_EVT_FALLING
// External Event Mode with Falling edge trigger detection
#define GPIO_MODE_EVT_RISING
//_FALLING External Event Mode with Rising/Falling edge trigger detection
*/
/*
#define GPIO_PIN_0  ((uint32_t)0x0001U)
#define GPIO_PIN_1  ((uint32_t)0x0002U)
#define GPIO_PIN_2  ((uint32_t)0x0004U)
#define GPIO_PIN_3  ((uint32_t)0x0008U)
#define GPIO_PIN_4  ((uint32_t)0x0010U)
#define GPIO_PIN_5  ((uint32_t)0x0020U)
#define GPIO_PIN_6  ((uint32_t)0x0040U)
#define GPIO_PIN_7  ((uint32_t)0x0080U)
#define GPIO_PIN_8  ((uint32_t)0x0100U)
#define GPIO_PIN_9  ((uint32_t)0x0200U)
#define GPIO_PIN_10 ((uint32_t)0x0400U)
#define GPIO_PIN_11 ((uint32_t)0x0800U)
#define GPIO_PIN_12 ((uint32_t)0x1000U)
#define GPIO_PIN_13 ((uint32_t)0x2000U)
#define GPIO_PIN_14 ((uint32_t)0x4000U)
#define GPIO_PIN_15 ((uint32_t)0x8000U)
*/

#define GPIO_PIN_MODE_INPUT		            ((uint32_t)0x0)
#define GPIO_PIN_MODE_OUTPUT	            ((uint32_t)0x1)
#define GPIO_PIN_MODE_AF		            ((uint32_t)0x2)
#define GPIO_PIN_MODE_ANALOG	            ((uint32_t)0x3)

#define GPIO_PIN_OP_TYPE_PP                 ((uint32_t)0x0)
#define GPIO_PIN_OP_TYPE_OD                 ((uint32_t)0x1)

#define GPIO_PIN_NO_PULL                    ((uint32_t)0x0)
#define GPIO_PIN_PULL_UP                    ((uint32_t)0x1)
#define GPIO_PIN_PULL_DOWN                  ((uint32_t)0x2)

#define GPIO_PIN_OP_SPEED_LOW               ((uint32_t)0x0)
#define GPIO_PIN_OP_SPEED_MEDIUM            ((uint32_t)0x1)
#define GPIO_PIN_OP_SPEED_HIGH              ((uint32_t)0x2)
#define GPIO_PIN_OP_SPEED_VERY_HIGH         ((uint32_t)0x3)

typedef struct {
	uint32_t Pin    ;
	uint32_t Mode   ;
	uint32_t Op_type;
	uint32_t Pull   ;
	uint32_t Speed  ;
	uint32_t Alternate;
}GPIO_InitPinTypeDef;

typedef enum{
	INT_RISING_EDGE ,
	INT_FALLING_EDGE ,
	INT_RISING_FALLING_EDGE
}int_edge_sel_t;

void HAL_GPIO_init (GPIO_TypeDef* GPIOX , GPIO_InitPinTypeDef* pInit_struct) ;
void HAL_GPIO_configInterrupt(uint16_t pin_no , int_edge_sel_t edge_sel);
void HAL_GPIO_enableInterrupt(uint16_t pin_no , IRQn_Type irq_no);
void HAL_GPIO_clearInterrupt(uint16_t pin_no );


#endif /* STM32L4XX_HAL_DRIVER_INC_HAL_GPIO_H_ */
