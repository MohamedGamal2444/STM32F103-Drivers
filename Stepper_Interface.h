/*
 * Stepper_Interface.h
 *
 *  Created on: Sep 5, 2021
 *      Author: Mohamed G.Mazen
 */

#ifndef INC_STEPPER_INTERFACE_H_
#define INC_STEPPER_INTERFACE_H_
#define CW 		1
#define CCW 	2
#define S_LOW	5
#define S_MID	10
#define S_HGH	15
#define STEPS_PER_REV 2038
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_adc.h"
//#include "stm32f103xb.h"
typedef struct {
	GPIO_TypeDef * GPIO_PORT;
	uint16_t GPIO_PIN[4];
	uint8_t Speed;
	uint16_t delay;
	uint8_t Step_counter;
}Stepper_struct;
void Stepper_MOV(Stepper_struct* Mx,uint8_t POS_RES);
void Stepper_SETUP(Stepper_struct* ST1);
void Stepper_Speed_SETUP(Stepper_struct* Mx,uint8_t speed_state);
#endif /* INC_STEPPER_INTERFACE_H_ */
