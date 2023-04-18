/*
 * Heating_Element_Led_program.c
 *
 *  Created on: Mar 28, 2023
 *      Author: ss210
 */


#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "heating_element_led_interface.h"
#include "heating_element_led_private.h"

void Heating_Element_Led_Initialize(void){
	DIO_SetPin_Direction(Heating_Element_Led_PRT,Heating_Element_Led,Heating_Element_Led_OUT);
	//Timer0_initalize();
}
void Heating_Element_Led_ON(void){
	DIO_SetPin_Value(Heating_Element_Led_PRT,Heating_Element_Led,Heating_Element_Led_HIGH);
}
void Heating_Element_Led_OFF(void){
	DIO_SetPin_Value(Heating_Element_Led_PRT,Heating_Element_Led,Heating_Element_Led_LOW);
}
void Heating_Element_Led_TGL(void){
	DIO_TogglePin_Value(Heating_Element_Led_PRT,Heating_Element_Led);
}
