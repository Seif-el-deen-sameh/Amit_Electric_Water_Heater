/*
 * led1_program.c
 *
 *  Created on: Mar 28, 2023
 *      Author: ss210
 */

#include "cooler_relay_interface.h"
#include "cooler_relay_private.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"

void Cooler_Relay_Initialize(void){
	DIO_SetPin_Direction(Cooler_Relay_PRT,Cooler_Relay,Cooler_Relay_OUT);
}
void Cooler_Relay_ON(void){
	DIO_SetPin_Value(Cooler_Relay_PRT,Cooler_Relay,Cooler_Relay_HIGH);
}
void Cooler_Relay_OFF(void){
	DIO_SetPin_Value(Cooler_Relay_PRT,Cooler_Relay,Cooler_Relay_LOW);
}
void Cooler_Relay_TGL(void){
	DIO_TogglePin_Value(Cooler_Relay_PRT,Cooler_Relay);
}
