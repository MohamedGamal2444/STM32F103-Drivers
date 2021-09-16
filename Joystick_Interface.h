/*
 * Joystick.h
 *
 *  Created on: Sep 5, 2021
 *      Author: Mohamed G.Mazen
 */

#ifndef INC_JOYSTICK_INTERFACE_H_
#define INC_JOYSTICK_INTERFACE_H_
/*direction macros*/
#define UP_RIGHT 			1
#define DOWN_LEFT	 		2

/*includes*/
#include "stm32f1xx_hal.h"
typedef struct{
	uint8_t POS1;
	uint8_t POS2;
}Joystick_struct;
/*function declarations*/
void JOYSTICK_GET_POS(Joystick_struct* J1,uint8_t ch1no,uint8_t ch2no,uint8_t polltimeout,ADC_HandleTypeDef hadc);

#endif /* INC_JOYSTICK_INTERFACE_H_ */
