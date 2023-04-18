/*
 * ADC_private.h
 *
 *  Created on: Apr 4, 2023
 *      Author: ss210
 */

#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_

#define ACSR    ( *(volatile u8*) 0x28)
#define ADMUX   ( *(volatile u8*) 0x27)
#define ADCSRA  ( *(volatile u8*) 0x26)
#define ADCH    ( *(volatile u8*) 0x25)
#define ADCL    ( *(volatile u8*) 0x24)
#define SFIOR	( *(volatile u8*) 0x50)

// #define ADC     (*(UINT16_T*) 0x04)

//#define SFIOR    ( *(volatile u8*)0x30)
typedef enum{
	ACSR_ACIS0=0,
	ACSR_ACIS1=1,
	ACSR_ACIC=2,
	ACSR_ACIE=3,
	ACSR_ACI=4,
	ACSR_ACO=5,
	ACSR_ACBG=6,
	ACSR_ACD=7
}ACSR_PIN;

typedef enum{
	ADMUX_MUX0=0,
	ADMUX_MUX1=1,
	ADMUX_MUX2=2,
	ADMUX_MUX3=3,
	ADMUX_MUX4=4,
	ADMUX_ADLAR=5,
	ADMUX_REFS0=6,
	ADMUX_REFS1=7
}ADMUX_PIN;

typedef enum{
	ADCSRA_ADPS0=0,
	ADCSRA_ADPS1=1,
	ADCSRA_ADPS2=2,
	ADCSRA_ADIE=3,
	ADCSRA_ADIF=4,
	ADCSRA_ADATE=5,
	ADCSRA_ADSC=6,
	ADCSRA_ADEN=7
}ADCSRA_PIN;

typedef enum{
//	SFIOR_PSR10=0,
//	SFIOR_PSR2=1,
//	SFIOR_PUD=2,
//	SFIOR_ACME=3,
	SFIOR_ADTS0=5,
	SFIOR_ADTS1=6,
	SFIOR_ADTS2=7
}SFIOR_PIN;

typedef enum{
	__2,
	__4,
	__8,
	__16,
	__32,
	__64,
	__128,
}Division_Factor;

typedef enum{
	_AREF,
	_AVCC,
	_Internal
}Reference_Selection;

typedef enum{
	Output_Toggle,
	Falling_Output_Edge,
	Rising_Output_Edge
}Analog_Comparator_Interrupt_Mode;

typedef enum{
	_left,
	_right
}store_dircetion;

typedef enum{
	Free_Running,
	Analog_Comparator,
	External_Interrupt_0,
	Timer0_Compare_Match,
	Timer0_Overflow,
	Timer1_Compare_Match_B,
	Timer1_Overflow,
	Timer1_Capture_Event
}trigger_source;

typedef enum{
	ch0=0,
	ch1=1,
	ch2=2,
	ch3=3,
	ch4=4,
	ch5=5,
	ch6=6,
	ch7=7
}channel;
#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
