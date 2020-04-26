/*
 * gpio.c
 *
 *  Created on: Feb 24, 2020
 *      Author: Loay
 */


#include <hal_gpio.h>


static void  HAL_GPIO_config_mode		(GPIO_TypeDef* GPIOX , uint32_t Pin  ,uint32_t Mode ) ;
static void  HAL_GPIO_config_op_type	(GPIO_TypeDef* GPIOX , uint32_t Pin  ,uint32_t Op_type ) ;
static void  HAL_GPIO_config_pull		(GPIO_TypeDef* GPIOX , uint32_t Pin ,uint32_t Pull ) ;
static void  HAL_GPIO_config_speed		(GPIO_TypeDef* GPIOX , uint32_t Pin ,uint32_t Speed) ;
static void  HAL_GPIO_config_alternate	(GPIO_TypeDef* GPIOX ,uint32_t Pin ,uint32_t Alternate ) ;
/*
typedef struct {
	uint32_t Pin    ;
	uint32_t Mode   ;
	uint32_t Op_type;
	uint32_t Pull   ;
	uint32_t Speed  ;
	uint32_t Alternate;
}GPIO_InitTypeDef;
*/
void HAL_GPIO_init (GPIO_TypeDef* GPIOX , GPIO_InitPinTypeDef* pInit_struct)
{
	HAL_GPIO_config_mode	 (GPIOX , pInit_struct->Pin ,pInit_struct->Mode ) ;
	HAL_GPIO_config_op_type  (GPIOX , pInit_struct->Pin ,pInit_struct->Op_type ) ;
	HAL_GPIO_config_pull	 (GPIOX , pInit_struct->Pin ,pInit_struct->Pull ) ;
	HAL_GPIO_config_speed	 (GPIOX , pInit_struct->Pin ,pInit_struct->Speed) ;
	HAL_GPIO_config_alternate(GPIOX , pInit_struct->Pin ,pInit_struct->Alternate ) ;
}

static void  HAL_GPIO_config_mode(GPIO_TypeDef* GPIOX , uint32_t Pin  ,uint32_t Mode )
{
	GPIOX->MODER &= (uint32_t)(~(0x03<<(Pin*2))) ; /*Clear the two bits to avoid accumulating modes*/
	GPIOX->MODER |= (uint32_t)(Mode<<(Pin*2)) ; /*Set the two bits with the new desired mode*/
}

static void  HAL_GPIO_config_op_type(GPIO_TypeDef* GPIOX , uint32_t Pin  ,uint32_t Op_type )
{
	GPIOX->OTYPER &= (uint32_t)(~(0x01<<(Pin))) ; /*Clear the bit to avoid accumulating modes*/
	GPIOX->OTYPER |= (uint32_t)(Op_type<<(Pin)) ; /*Set the bit with the new desired mode*/
}
static void  HAL_GPIO_config_pull(GPIO_TypeDef* GPIOX , uint32_t Pin ,uint32_t Pull )
{
	GPIOX->PUPDR &= (uint32_t)(~(0x03<<(Pin*2))) ; /*Clear the two bits to avoid accumulating modes*/
	GPIOX->PUPDR |= (uint32_t)(Pull<<(Pin*2)) ; /*Set the two bits with the new desired mode*/
}
static void  HAL_GPIO_config_speed(GPIO_TypeDef* GPIOX , uint32_t Pin ,uint32_t Speed)
{
	GPIOX->OSPEEDR &= (uint32_t)(~(0x03<<(Pin*2))) ; /*Clear the two bits to avoid accumulating modes*/
	GPIOX->OSPEEDR |= (uint32_t)(Speed<<(Pin*2)) ; /*Set the two bits with the new desired mode*/
}
static void  HAL_GPIO_config_alternate(GPIO_TypeDef* GPIOX ,uint32_t Pin ,uint32_t Alternate )
{
	if (Pin <= 7 ){
		GPIOX->AFR[0] &= (uint32_t)(~(0x0F<<(Pin*4))) ; /*Clear the four bits to avoid accumulating modes*/
		GPIOX->AFR[0] |= (uint32_t)(Alternate<<(Pin*4)) ; /*Set the four bits with the new desired mode*/
	}else {
		Pin = Pin%8  ;
		GPIOX->AFR[1] &= (uint32_t)(~(0x0F<<(Pin*4))) ; /*Clear the four bits to avoid accumulating modes*/
		GPIOX->AFR[1] |= (uint32_t)(Alternate<<(Pin*4)) ; /*Set the four bits with the new desired mode*/
	}
}
