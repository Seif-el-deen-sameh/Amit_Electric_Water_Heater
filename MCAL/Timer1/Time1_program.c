/*
 * Timer1_program.c
 *
 *  Created on: Apr 6, 2023
 *      Author: ss210
 */

#include "Timer1_configuration.h"
#include "Timer1_interface.h"
#include "Timer1_private.h"
#include "std_types.h"
#include "bit_math.h"
void(*ptrt0)(void);
void(*ptrt0_1)(void);
void(*ptrt0_2)(void);
/*void Timer1_Set_prescalar(Prescalar value){
	switch (value)
	{

	}
}
void Timer1_Set_preload(u8 value){

}
void Timer1_Set_compare(u8 value){

}
void Timer1_Set_mode(Mode value){
	switch (value)
	{

	}
}
void Timer1_OC0_mode(OC0_Mode mode){
switch (mode)
{

}
}*/
void Timer1_initalize(){
	//set mode
	clr_bit(TCCR1A,0);
	clr_bit(TCCR1A,1);
	clr_bit(TCCR1B,3);
	clr_bit(TCCR1B,4);
	// set preload
	TCNT1=6250;
	//set prescalar
	clr_bit(TCCR1B,0);
	clr_bit(TCCR1B,1);
	set_bit(TCCR1B,2);

}
/*void Timer1_enable_overflow_intterrupt(){

}
void Timer1_enable_compare_intterrupt(){

}
void Timer1_disable_overflow_intterrupt(){

}
void Timer1_disable_compare_intterrupt(){

}
u8 Timer1_overflow_intterrupt_Flag_Value(void){

}
u8 Timer1_compare_intterrup_Flag_Value(void){

}*/
void ISR_Timer1_Overflow(void(*copy_ptrtofunction)(void))
{
	ptrt0_2=copy_ptrtofunction;
}

void __vector_7(void)  __attribute__((signal));
void __vector_7(void){
	ptrt0();
}
void __vector_8(void)  __attribute__((signal));
void __vector_8(void){
	ptrt0_1();
}
void __vector_9(void)  __attribute__((signal));
void __vector_9(void){
	ptrt0_2();
}
