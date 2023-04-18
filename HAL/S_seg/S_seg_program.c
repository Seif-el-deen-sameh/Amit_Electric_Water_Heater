/*
 * S_seg_program.c
 *
 *  Created on: Mar 28, 2023
 *      Author: ss210
 */
#include "S_seg_interface.h"
#include "S_seg_configuration.h"
#include "S_seg_private.h"
#include "bit_math.h"
#include "std_types.h"
#include <util/delay.h>
void S_seg_Initialize(S_seg_mode mode){
				switch(mode)
				{
					case cathode:
						DIO_SetPort_Direction(S_seg,DIO_PORT_HIGH);
						DIO_SetPin_Direction(S_seg_enable_port_uints,S_seg_uints_digit,DIO_OUTPUT);
						DIO_SetPin_Direction(S_seg_enable_port_tens,S_seg_tens_digit,DIO_OUTPUT);
						DIO_SetPin_Value(S_seg_enable_port_uints,S_seg_uints_digit,DIO_HIGH);
						DIO_SetPin_Value(S_seg_enable_port_tens,S_seg_tens_digit,DIO_HIGH);
						DIO_SetPort_Value(S_seg,DIO_PORT_LOW);
					break;
					case anode:
						DIO_SetPort_Direction(S_seg,DIO_PORT_HIGH);
						DIO_SetPin_Direction(S_seg_enable_port_uints,S_seg_uints_digit,DIO_OUTPUT);
						DIO_SetPin_Direction(S_seg_enable_port_tens,S_seg_tens_digit,DIO_OUTPUT);
						DIO_SetPin_Value(S_seg_enable_port_uints,S_seg_uints_digit,DIO_LOW);
						DIO_SetPin_Value(S_seg_enable_port_tens,S_seg_tens_digit,DIO_LOW);
						DIO_SetPort_Value(S_seg,DIO_PORT_HIGH);
					break;
				}
}
void S_seg_clear(S_seg_mode mode){
	switch(mode)
					{
						case cathode:
							set_bit(PORTD,7);
							set_bit(PORTD,6);
						break;
						case anode:
							clr_bit(PORTD,7);
							clr_bit(PORTD,6);
						break;
					}
}
void S_seg_print_two_segments(u8 num){
	volatile u8 uints=0;
	volatile u8 tens=0;
	uints=(num-((num/10)*10));
	tens=(num/10);
	PORTC &= 0b1110000;
	PORTC |= tens;
	set_bit(PORTD,7);
	clr_bit(PORTD,6);
	_delay_ms(10);
	PORTC &= 0b1110000;
	PORTC |= uints;
	clr_bit(PORTD,7);
	set_bit(PORTD,6);
	_delay_ms(10);
}
