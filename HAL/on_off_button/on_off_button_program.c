/*
 * button_program.c
 *
 *  Created on: Apr 1, 2023
 *      Author: ss210
 */


#include "DIO_Interface.h"
#include <util/delay.h>
#include "External_interrupt_private.h"
#include "on_off_button_private.h"
#include "on_off_button_interface.h"
#include "DIO_Private.h"

void On_Off_Button_Initialize(void)
{

	DIO_SetPin_Direction(On_Off_Button_PRT, On_Off_Button, On_Off_Button_IN);
	DIO_ActivatePin_PullUp(On_Off_Button_PRT, On_Off_Button);
	Set_External_Interrupt_Pin_Trigger(INT0,falling_edge);
	External_Interrupt_Pin_Enable(INT0);
}
