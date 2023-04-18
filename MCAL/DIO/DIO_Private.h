/*
 * DIO_Address.h
 *
 * Created: 1/6/2023 10:50:23 AM
 *  Author: ss210
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#include "std_types.h"
// define registers needed for driver
#define DDRA	( *(volatile u8*) 0x3A )
#define DDRB	( *(volatile u8*) 0x37 )
#define DDRC	( *(volatile u8*) 0x34 )
#define DDRD	( *(volatile u8*) 0x31 )

#define PORTA	( *(volatile u8*) 0x3B )
#define PORTB	( *(volatile u8*) 0x38 )
#define PORTC	( *(volatile u8*) 0x35 )
#define PORTD	( *(volatile u8*) 0x32 )

#define PINA	( *(volatile u8*) 0x39 )
#define PINB	( *(volatile u8*) 0x36 )
#define PINC	( *(volatile u8*) 0x33 )
#define PIND	( *(volatile u8*) 0x30 )

// define names for required values avoiding magic numbers
typedef enum{
	DIO_PORTA=0,
	DIO_PORTB=1,
	DIO_PORTC=2,
	DIO_PORTD=3
}DIO_PORT;

typedef enum{
	DIO_PIN0=0,
	DIO_PIN1=1,
	DIO_PIN2=2,
	DIO_PIN3=3,
	DIO_PIN4=4,
	DIO_PIN5=5,
	DIO_PIN6=6,
	DIO_PIN7=7
}DIO_PIN;

typedef enum{
	DIO_INPUT=0,
	DIO_OUTPUT=1
}DIO_State;

typedef enum{
	DIO_HIGH=1,
	DIO_LOW=0
}DIO_Status;

typedef enum{
	DIO_PORT_HIGH=0xff,
	DIO_PORT_LOW=0x00
}DIO_Status_Port;

#endif /* DIO_ADDRESS_H_ */
