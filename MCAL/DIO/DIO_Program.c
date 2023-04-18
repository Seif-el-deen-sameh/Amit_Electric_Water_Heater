/*
 * DIO_interface.c
 *
 * Created: 1/6/2023 10:49:02 AM
 *  Author: ss210
 */ 
#include <DIO_Interface.h>

void DIO_SetPin_Direction(DIO_PORT port, DIO_PIN pin, DIO_State state)
{
	switch(state)
	{
		case DIO_INPUT:
		switch(port)
		{
			case DIO_PORTA:
			clr_bit(DDRA, pin);
			break;
			case DIO_PORTB:
			clr_bit(DDRB, pin);
			break;
			case DIO_PORTC:
			clr_bit(DDRC, pin);
			break;
			case DIO_PORTD:
			clr_bit(DDRD, pin);
			break;
		}
		break;
		case DIO_OUTPUT:
		switch(port)
		{
			case DIO_PORTA:
			set_bit(DDRA, pin);
			break;
			case DIO_PORTB:
			set_bit(DDRB, pin);
			break;
			case DIO_PORTC:
			set_bit(DDRC, pin);
			break;
			case DIO_PORTD:
			set_bit(DDRD, pin);
			break;
		}
		break;
	}
}
//Define status as low or high
void DIO_SetPin_Value(DIO_PORT port, DIO_PIN pin, DIO_Status status)
{
	switch(status)
	{
		case DIO_LOW:
		switch(port)
		{
			case DIO_PORTA:
			clr_bit(PORTA, pin);
			break;
			case DIO_PORTB:
			clr_bit(PORTB, pin);
			break;
			case DIO_PORTC:
			clr_bit(PORTC, pin);
			break;
			case DIO_PORTD:
			clr_bit(PORTD, pin);
			break;
		}
		break;
		case DIO_HIGH:
		switch(port)
		{
			case DIO_PORTA:
			set_bit(PORTA, pin);
			break;
			case DIO_PORTB:
			set_bit(PORTB, pin);
			break;
			case DIO_PORTC:
			set_bit(PORTC, pin);
			break;
			case DIO_PORTD:
			set_bit(PORTD, pin);
			break;
		}
		break;
	}
}
//Toggle value (Not Gate)
void DIO_TogglePin_Value(DIO_PORT port, DIO_PIN pin)
{
	switch(port)
	{
		case DIO_PORTA:
		tgl_bit(PORTA, pin);
		break;
		case DIO_PORTB:
		tgl_bit(PORTB, pin);
		break;
		case DIO_PORTC:
		tgl_bit(PORTC, pin);
		break;
		case DIO_PORTD:
		tgl_bit(PORTD, pin);
		break;
	}
}
//Get pin value low or high
u8 DIO_ReadPin_Value(DIO_PORT port, DIO_PIN pin)
{
	u8 val = 0;
	switch (port)
	{
		case DIO_PORTA:
		val = get_bit(PINA, pin);
		break;
		case DIO_PORTB:
		val = get_bit(PINB, pin);
		break;
		case DIO_PORTC:
		val = get_bit(PINC, pin);
		break;
		case DIO_PORTD:
		val = get_bit(PIND, pin);
		break;
	}
	return val;
}
//Activate internal pull up
void DIO_ActivatePin_PullUp(DIO_PORT port, DIO_PIN pin)
{
	switch(port)
	{
		case DIO_PORTA:
		set_bit(PORTA, pin);
		break;
		case DIO_PORTB:
		set_bit(PORTB, pin);
		break;
		case DIO_PORTC:
		set_bit(PORTC, pin);
		break;
		case DIO_PORTD:
		set_bit(PORTD, pin);
		break;
	}
}
/*------------------------------------PORTS----------------------------------------*/
//Define direction as input or output
void DIO_SetPort_Direction(DIO_PORT port, DIO_State state)
{
	switch (state)
	{
		case DIO_INPUT:
		switch(port)
		{
			case DIO_PORTA:
			DDRA = DIO_PORT_LOW;
			break;
			case DIO_PORTB:
			DDRB = DIO_PORT_LOW;
			break;
			case DIO_PORTC:
			DDRC = DIO_PORT_LOW;
			break;
			case DIO_PORTD:
			DDRD = DIO_PORT_LOW;
			break;
		}
		break;
		case DIO_OUTPUT:
		switch(port)
		{
			case DIO_PORTA:
			DDRA = DIO_PORT_HIGH;
			break;
			case DIO_PORTB:
			DDRB = DIO_PORT_HIGH;
			break;
			case DIO_PORTC:
			DDRC = DIO_PORT_HIGH;
			break;
			case DIO_PORTD:
			DDRD = DIO_PORT_HIGH;
			break;
		}
		break;
	}
}
//Define status as low or high
void DIO_SetPort_Value(DIO_PORT port, u8 value)
{

		switch(port)
		{
			case DIO_PORTA:
			PORTA =value;
			break;
			case DIO_PORTB:
			PORTB =value;
			break;
			case DIO_PORTC:
			PORTC = value;
			break;
			case DIO_PORTD:
			PORTD = value;
			break;
		}

}
//Toggle value (Not Gate)
void DIO_TogglePort_Value(DIO_PORT port)
{
	switch(port)
	{
		case DIO_PORTA:
		PORTA ^= DIO_PORT_HIGH;
		break;
		case DIO_PORTB:
		PORTB ^= DIO_PORT_HIGH;
		break;
		case DIO_PORTC:
		PORTC ^= DIO_PORT_HIGH;
		break;
		case DIO_PORTD:
		PORTD ^= DIO_PORT_HIGH;
		break;
	}
}
//Get pin value low or high
u8 DIO_ReadPort_Value(DIO_PORT port)
{
	u8 val = 0;
	switch (port)
	{
		case DIO_PORTA:
		val = PINA;
		break;
		case DIO_PORTB:
		val = PINB;
		break;
		case DIO_PORTC:
		val = PINC;
		break;
		case DIO_PORTD:
		val = PIND;
		break;
	}
	return val;
}
//Activate internal pull up
void DIO_ActivatePort_PullUp(DIO_PORT port)
{
	switch(port)
	{
		case DIO_PORTA:
		PORTA = DIO_PORT_HIGH;
		break;
		case DIO_PORTB:
		PORTB = DIO_PORT_HIGH;
		break;
		case DIO_PORTC:
		PORTC = DIO_PORT_HIGH;
		break;
		case DIO_PORTD:
		PORTD = DIO_PORT_HIGH;
		break;
	}
}
