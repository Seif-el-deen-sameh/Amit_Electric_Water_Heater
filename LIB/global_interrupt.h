/*
 * global_interrupt.h
 *
 *  Created on: Apr 13, 2023
 *      Author: ss210
 */

#ifndef LIB_GLOBAL_INTERRUPT_H_
#define LIB_GLOBAL_INTERRUPT_H_
#define SREG   ( *(volatile u8*)0x5f)
#define Global_interrupt_enable			set_bit(SREG,7)
#define Global_interrupt_disable	    clr_bit(SREG,7)


#endif /* LIB_GLOBAL_INTERRUPT_H_ */
