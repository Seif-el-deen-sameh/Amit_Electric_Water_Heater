/*
 * Heater_Relay_program.c
 *
 *  Created on: Mar 28, 2023
 *      Author: ss210
 */

#include "heater_relay_interface.h"
#include "heater_relay_private.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"
void Heater_Relay_Initialize(void){
	DIO_SetPin_Direction(Heater_Relay_PRT,Heater_Relay,Heater_Relay_OUT);
}
void Heater_Relay_ON(void){
	DIO_SetPin_Value(Heater_Relay_PRT,Heater_Relay,Heater_Relay_HIGH);
}
void Heater_Relay_OFF(void){
	DIO_SetPin_Value(Heater_Relay_PRT,Heater_Relay,Heater_Relay_LOW);
}
void Heater_Relay_TGL(void){
	DIO_TogglePin_Value(Heater_Relay_PRT,Heater_Relay);
}
