/*
 * External_interrupt_program.c
 *
 *  Created on: Apr 2, 2023
 *      Author: ss210
 */


#include "std_types.h"
#include "bit_math.h"
#include "External_interrupt_interface.h"
#include "External_interrupt_private.h"

void(*Global_ptrToFunINT0)(void) = 0 ;
void(*Global_ptrToFunINT1)(void) = 0 ;
void(*Global_ptrToFunINT2)(void) = 0 ;

void Set_External_Interrupt_Pin_Trigger(Interrupt_pin pin ,Interrupt_trigger_type type){
	switch(pin)
	{
	case INT0:
		switch(type)
		{
		case rising_edge:
			set_bit(MCUCR,MCUCR_ISC00);
			set_bit(MCUCR,MCUCR_ISC01);
			break;
		case logic_change:
			set_bit(MCUCR,MCUCR_ISC00);
			clr_bit(MCUCR,MCUCR_ISC01);
			break;
		case falling_edge:
			clr_bit(MCUCR,MCUCR_ISC00);
			set_bit(MCUCR,MCUCR_ISC01);
			break;
		case low_level:
			clr_bit(MCUCR,MCUCR_ISC00);
			clr_bit(MCUCR,MCUCR_ISC01);
			break;
		}
		break;
		case INT1:
			switch(type)
			{
			case rising_edge:
				set_bit(MCUCR,MCUCR_ISC10);
				set_bit(MCUCR,MCUCR_ISC11);
				break;
			case logic_change:
				set_bit(MCUCR,MCUCR_ISC10);
				clr_bit(MCUCR,MCUCR_ISC11);
				break;
			case falling_edge:
				clr_bit(MCUCR,MCUCR_ISC10);
				set_bit(MCUCR,MCUCR_ISC11);
				break;
			case low_level:
				clr_bit(MCUCR,MCUCR_ISC10);
				clr_bit(MCUCR,MCUCR_ISC11);
				break;
			}
			break;
			case INT2:
				switch(type)
				{
				case rising_edge:
					set_bit(MCUCSR,MCUCSR_ISC2);
					break;
				case falling_edge:
					clr_bit(MCUCSR,MCUCSR_ISC2);
					break;
				}
				break;
	}
}
u8 Check_External_Interrupt_Flag(Interrupt_pin pin){
	u8 value = 0;
	switch(pin)
	{
	case INT0:
		value = get_bit(GIFR,GIFR_INT0);
		break;
	case INT1:
		value = get_bit(GIFR,GIFR_INT1);
		break;
	case INT2:
		value = get_bit(GIFR,GIFR_INT2);
		break;
	}
	return value;
}
void External_Interrupt_Pin_Disable(Interrupt_pin pin){
	switch(pin)
	{
	case INT0:
		clr_bit(GICR,GICR_INT0);
		break;
	case INT1:
		clr_bit(GICR,GICR_INT1);
		break;
	case INT2:
		clr_bit(GICR,GICR_INT2);
		break;
	}
}
void External_Interrupt_Pin_Enable(Interrupt_pin pin){
	switch(pin)
	{
	case INT0:
		set_bit(GICR,GICR_INT0);
		break;
	case INT1:
		set_bit(GICR,GICR_INT1);
		break;
	case INT2:
		set_bit(GICR,GICR_INT2);
		break;
	}
}
void EXTI_voidSetCallBack(u8 Copy_IntIndex , void(*Copy_ptrToFunction)(void))
{
		switch (Copy_IntIndex)
		{
			case INT0:
				Global_ptrToFunINT0 = Copy_ptrToFunction;
				break;
			case INT1:
				Global_ptrToFunINT1 = Copy_ptrToFunction;
				break;
			case INT2:
				Global_ptrToFunINT2 = Copy_ptrToFunction;
				break;
		}
	}

void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
		Global_ptrToFunINT0();
}
/*======================================================================================================*/
void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
		Global_ptrToFunINT1();
}
/*======================================================================================================*/
void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
		Global_ptrToFunINT2();
}
