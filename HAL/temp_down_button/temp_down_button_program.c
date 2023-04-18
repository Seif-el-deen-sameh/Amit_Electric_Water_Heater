/*
 * button_program.c
 *
 *  Created on: Apr 1, 2023
 *      Author: ss210
 */


#include "DIO_Interface.h"
#include "External_interrupt_interface.h"
#include "temp_down_button_private.h"
#include "temp_down_button_interface.h"
void Temp_Down_Button_Initialize(void)
{
	DIO_SetPin_Direction(Temp_Down_Button_PRT, Temp_Down_Button, Temp_Down_Button_IN);
	DIO_ActivatePin_PullUp(Temp_Down_Button_PRT, Temp_Down_Button);
	Set_External_Interrupt_Pin_Trigger(INT2,falling_edge);
	External_Interrupt_Pin_Enable(INT2);
}
