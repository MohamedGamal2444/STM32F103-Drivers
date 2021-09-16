/*
 * Joystick.c
 *
 *  Created on: Sep 5, 2021
 *      Author: Mohamed G.Mazen
 */
#include <Joystick_Interface.h>
void JOYSTICK_GET_POS(Joystick_struct* J1,uint8_t ch1no,uint8_t ch2no,uint8_t polltimeout,ADC_HandleTypeDef hadc){
	uint32_t ADC1_RES,ADC2_RES;
	HAL_ADCEx_InjectedStart_IT(&hadc);
	HAL_ADC_PollForConversion(&hadc, polltimeout);
	ADC1_RES=HAL_JADC_GetValue( &hadc,ch1no);
	ADC2_RES=HAL_JADC_GetValue( &hadc,ch2no);
	if (ADC1_RES<1200){
		J1->POS1=UP_RIGHT;
	}
	else if (ADC1_RES>3000){
		J1->POS1=DOWN_LEFT;
	}
	else{
		J1->POS1=0;
	}
	if (ADC2_RES<1200){
		J1->POS2=UP_RIGHT;
	}
	else if (ADC2_RES>3000){
		J1->POS2=DOWN_LEFT;
	}
	else{
			J1->POS2=0;
	}
}
