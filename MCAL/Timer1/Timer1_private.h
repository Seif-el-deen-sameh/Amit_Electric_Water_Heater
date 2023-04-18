/*
 * Timer0_private.h
 *
 *  Created on: Apr 6, 2023
 *      Author: ss210
 */

#ifndef MCAL_TIMER1_TIMER0_PRIVATE_H_
#define MCAL_TIMER1_TIMER0_PRIVATE_H_

#include "std_types.h"

#define  TCCR1A (*(volatile u8*)0x4F)
#define	 TCCR1B (*(volatile u8*)0x4E)
#define	 TCNT1H (*(volatile u8*)0x4D)
#define	 TCNT1L (*(volatile u8*)0x4C)
#define	 TCNT1 (*(volatile u16*)0x4C)
#define	 OCR1A (*(volatile u16*)0x4A)
#define	 OCR1B (*(volatile u16*)0x48)
#define	 ICR1  (*(volatile u16*)0x46)
#define  TIMSK  (*(volatile u8*)0x59)
#define  TIFR   (*(volatile u8*)0x38)

/*typedef enum{
	TCCR0_FOC0=7,
	TCCR0_WGM00=6,
	TCCR0_COM01=5,
	TCCR0_COM00=4,
	TCCR0_WGM01=3,
	TCCR0_CS02=2,
	TCCR0_CS01=1,
	TCCR0_CS00=0
}TCCR0_BIT;*/

/*typedef enum{
//	TIMSK_OCIE2=7,
//	TIMSK_TOIE2=6,
//	TIMSK_TICIE1=5,
//	TIMSK_OCIE1A=4,
//	TIMSK_OCIE1B=3,
//	TIMSK_TOIE1=2,
	TIMSK_OCIE0=1,
	TIMSK_TOIE0=0
}TIMSK_BIT;*/

/*typedef enum{
//	TIFR_OCF2=7,
//	TIFR_TOV2=6,
//	TIFR_ICF1=5,
//	TIFR_OCF1A=4,
//	TIFR_OCF1B=3,
//	TIFR_TOV1=2,
	TIFR_OCF0=1,
	TIFR_TOV0=0
}TIFR_BIT;*/

/*typedef enum{
	_8,
	_64,
	_256,
	_1024,
	_none,
	_no_prescalar,
	_external_fall,
	_external_rise
}Prescalar;*/

/*typedef enum{
	CTC,
	PWM,
	Fast_PWM,
	Timer
}Mode;*/
/*typedef enum{
	Disconnected,
	Toggle,
	Clear,
	Set
}OC0_Mode;*/

#endif /* MCAL_TIMER0_TIMER0_PRIVATE_H_ */
