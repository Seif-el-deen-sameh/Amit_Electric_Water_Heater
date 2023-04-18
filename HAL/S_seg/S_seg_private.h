/*
 * S_seg_private.h
 *
 *  Created on: Mar 28, 2023
 *      Author: ss210
 */

#ifndef HAL_S_SEG_S_SEG_PRIVATE_H_
#define HAL_S_SEG_S_SEG_PRIVATE_H_
#include "DIO_Private.h"
#define S_seg         				DIO_PORTC
#define S_seg_enable_port_uints		DIO_PORTD
#define S_seg_enable_port_tens		DIO_PORTD
#define S_seg_uints_digit       	DIO_PIN6
#define S_seg_tens_digit        	DIO_PIN7
typedef enum{
	zero=0,
	one=1,
	two=2,
	three=3,
	four=4,
	five=5,
	six=6,
	seven=7,
	eight=8,
	nine=9
}S_seg_num;
typedef enum{
	cathode,
	anode
}S_seg_mode;

#endif /* HAL_S_SEG_S_SEG_PRIVATE_H_ */
