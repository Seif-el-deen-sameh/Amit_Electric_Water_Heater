/*
 * button_program.c
 *
 *  Created on: Apr 1, 2023
 *      Author: ss210
 */


#include "DIO_Interface.h"
#include "External_interrupt_interface.h"
#include "temp_up_button_private.h"
#include "temp_up_button_interface.h"
void Temp_Up_Button_Initialize(void)
{
	DIO_SetPin_Direction(Temp_Up_Button_PRT, Temp_Up_Button, Temp_Up_Button_IN);
	DIO_ActivatePin_PullUp(Temp_Up_Button_PRT, Temp_Up_Button);
	Set_External_Interrupt_Pin_Trigger(INT1,rising_edge);
	External_Interrupt_Pin_Enable(INT1);
}
