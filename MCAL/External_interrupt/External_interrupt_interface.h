/*
 * External_interrupt_interface.h
 *
 *  Created on: Apr 2, 2023
 *      Author: ss210
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_INTERFACE_H_
#define MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_INTERFACE_H_

#include "External_interrupt_private.h"

void Enable_interupt(void);
void Disable_interrupt(void);
void Set_External_Interrupt_Pin_Trigger(Interrupt_pin pin ,Interrupt_trigger_type type);
void External_Interrupt_Pin_Disable(Interrupt_pin pin);
void External_Interrupt_Pin_Enable(Interrupt_pin pin);
u8 Check_External_Interrupt_Flag(Interrupt_pin pin);
void EXTI_voidSetCallBack(u8 Copy_IntIndex , void(*Copy_ptrToFunction)(void));
#define    INT_0             0
#define    INT_1             1
#define    INT_2             2



#endif /* MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_INTERFACE_H_ */
