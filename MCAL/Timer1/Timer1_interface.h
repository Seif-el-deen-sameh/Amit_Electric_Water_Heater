/*
 * Timer1_interface.h
 *
 *  Created on: Apr 6, 2023
 *      Author: ss210
 */

#ifndef MCAL_TIMER1_Timer1_INTERFACE_H_
#define MCAL_TIMER1_Timer1_INTERFACE_H_

#include <Timer1/Timer1_private.h>

/*void Timer1_Set_prescalar(Prescalar value);
void Timer1_Set_preload(u8 value);
void Timer1_Set_compare(u8 value);
void Timer1_Set_mode(Mode value);
void Timer1_OC0_mode(OC0_Mode mode);*/
void Timer1_initalize();
/*void Timer1_enable_overflow_intterrupt();
void Timer1_enable_compare_intterrupt();
void Timer1_disable_overflow_intterrupt();
void Timer1_disable_compare_intterrupt();
u8 Timer1_overflow_intterrupt_Flag_Value(void);
u8 Timer1_compare_intterrup_Flag_Value(void);
void ISR_Timer1_Overflow(void(*copy_ptrtofunction)(void));
void ISR_Timer1_Compare_Match(void(*copy_ptrtofunction)(void));*/


#endif /* MCAL_Timer1_Timer1_INTERFACE_H_ */
