/*
 * External_interrupt_private.h
 *
 *  Created on: Apr 2, 2023
 *      Author: ss210
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_PRIVATE_H_
#define MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_PRIVATE_H_

#define MCUCSR ( *(volatile u8*)0x54)
#define MCUCR  ( *(volatile u8*)0x55)
#define GICR   ( *(volatile u8*)0x5B)
#define GIFR   ( *(volatile u8*)0x5A)


typedef enum{
	//GICR_IVCE=0,
	//GICR_IVSEL=1,
	//GICR_PIN2=2,
	//GICR_PIN3=3,
	//GICR_PIN4=4,
	GICR_INT2=5,
	GICR_INT0=6,
	GICR_INT1=7
}GICR_PIN;

typedef enum{
	//GIFR_PIN0=0,
	//GIFR_PIN1=1,
	//GIFR_PIN2=2,
	//GIFR_PIN3=3,
	//GIFR_PIN4=4,
	GIFR_INT2=5,
	GIFR_INT0=6,
	GIFR_INT1=7
}GIFR_PIN;

typedef enum{
	MCUCR_ISC00=0,
	MCUCR_ISC01=1,
	MCUCR_ISC10=2,
	MCUCR_ISC11=3,
	MCUCR_SM0=4,
	MCUCR_SM1=5,
	MCUCR_SM2=6,
	MCUCR_SE=7
}MCUCR_PIN;

typedef enum{
	MCUCSR_PORF=0,
	MCUCSR_EXTRF=1,
	MCUCSR_BORF=2,
	MCUCSR_WDRF=3,
	MCUCSR_JTRF=4,
	//MCUCSR_PIN5=5,
	MCUCSR_ISC2=6,
	MCUCSR_JDT=7
}MCUCSR_PIN;

typedef enum{
	falling_edge,
	rising_edge,
	logic_change,
	low_level
}Interrupt_trigger_type;

typedef enum{
	INT0=0,
	INT1=1,
	INT2=2
}Interrupt_pin;
#endif /* MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_PRIVATE_H_ */
