/*
 * Stepper_program.c
 *
 *  Created on: Sep 5, 2021
 *      Author: Mohamed G.Mazen
 */

#include <Stepper_Interface.h>
#include <Stepper_private.h>
#include <LCM.h>
#include<main.h>
uint8_t ticktime=0;
void Stepper_SETUP(Stepper_struct* ST1){
	ST1->delay=(uint8_t) (((1000/((ST1->Speed/60.0)*STEPS_PER_REV))/2)+0.5);
	Delay_LCM=lcm(ST1->delay, Delay_LCM);
}
void Stepper_Speed_SETUP(Stepper_struct* Mx,uint8_t speed_state){
	switch (speed_state){
	case 1:
		Mx->Speed=S_LOW;
		Stepper_SETUP(Mx);
		break;
	case 2:
		Mx->Speed=S_MID;
		Stepper_SETUP(Mx);
		break;
	case 3:
		Mx->Speed=S_HGH;
		Stepper_SETUP(Mx);
		break;
	}
}
void Stepper_MOV(Stepper_struct* Mx,uint8_t POS_RES){
	/*direction is clock wise (0)or counter clock wise (1)*/
	/*speed in rev/min*/
	/*the 28BYJ-48 stepper motor takes 8 steps to make 1 revolution but there is a gear ratio in the shaft
	 * so to make a 1 real revolution we have to run approximately 2038 steps*/
	if (ticktime%Mx->delay==0){
		if (POS_RES!=0){
			/*The function that makes the motor steps*/
			switch (POS_RES){
				case 1:
					Mx->Step_counter++;
					switch (Mx->Step_counter){
					case 1:
						/*STEP 1*/
						HAL_GPIO_WritePin(Mx->GPIO_PORT, Mx->GPIO_PIN[3], GPIO_PIN_SET);
						HAL_GPIO_WritePin(Mx->GPIO_PORT, Mx->GPIO_PIN[0], GPIO_PIN_RESET);
						break;
					case 2:
						/*STEP 2*/
						HAL_GPIO_WritePin(Mx->GPIO_PORT, Mx->GPIO_PIN[2], GPIO_PIN_SET);
						break;
					case 3:
						/*STEP 3*/
						HAL_GPIO_WritePin(Mx->GPIO_PORT, Mx->GPIO_PIN[3], GPIO_PIN_RESET);
						break;
					case 4:
						/*STEP 4*/
						HAL_GPIO_WritePin(Mx->GPIO_PORT, Mx->GPIO_PIN[1], GPIO_PIN_SET);
						break;
					case 5:
						/*STEP 5*/
						HAL_GPIO_WritePin(Mx->GPIO_PORT, Mx->GPIO_PIN[2], GPIO_PIN_RESET);
						break;
					case 6:
						/*STEP 6*/
						HAL_GPIO_WritePin(Mx->GPIO_PORT, Mx->GPIO_PIN[0], GPIO_PIN_SET);
						break;
					case 7:
						/*STEP 7*/
						HAL_GPIO_WritePin(Mx->GPIO_PORT, Mx->GPIO_PIN[1], GPIO_PIN_RESET);
						break;
					case 8:
						/*STEP 8*/
						HAL_GPIO_WritePin(Mx->GPIO_PORT, Mx->GPIO_PIN[3], GPIO_PIN_SET);
						Mx->Step_counter=0;
						break;
					default:
						break;
					}
				break;
				case 2:
					Mx->Step_counter++;
					switch (Mx->Step_counter){
						case 1:
							/*STEP 1*/
							HAL_GPIO_WritePin(Mx->GPIO_PORT, Mx->GPIO_PIN[0], GPIO_PIN_SET);
							HAL_GPIO_WritePin(Mx->GPIO_PORT, Mx->GPIO_PIN[3], GPIO_PIN_RESET);
							break;
						case 2:
							/*STEP 2*/
							HAL_GPIO_WritePin(Mx->GPIO_PORT, Mx->GPIO_PIN[1], GPIO_PIN_SET);
							break;
						case 3:
							/*STEP 3*/
							HAL_GPIO_WritePin(Mx->GPIO_PORT, Mx->GPIO_PIN[0], GPIO_PIN_RESET);
							break;
						case 4:
							/*STEP 4*/
							HAL_GPIO_WritePin(Mx->GPIO_PORT, Mx->GPIO_PIN[2], GPIO_PIN_SET);
							break;
						case 5:
							/*STEP 5*/
							HAL_GPIO_WritePin(Mx->GPIO_PORT, Mx->GPIO_PIN[1], GPIO_PIN_RESET);
							break;
						case 6:
							/*STEP 6*/
							HAL_GPIO_WritePin(Mx->GPIO_PORT, Mx->GPIO_PIN[3], GPIO_PIN_SET);
							break;
						case 7:
							/*STEP 7*/
							HAL_GPIO_WritePin(Mx->GPIO_PORT, Mx->GPIO_PIN[2], GPIO_PIN_RESET);
							break;
						case 8:
							/*STEP 8*/
							HAL_GPIO_WritePin(Mx->GPIO_PORT, Mx->GPIO_PIN[0], GPIO_PIN_SET);
							Mx->Step_counter=0;
							break;
						}
					break;
			}
		}
		if (ticktime==Delay_LCM){
			ticktime=0;
		}
	}
}
