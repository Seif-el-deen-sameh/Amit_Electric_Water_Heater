/*
 * bit_math.h
 *
 *  Created on: Mar 21, 2023
 *      Author: ss210
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define set_bit(reg,bit) reg|=(1<<bit)  						 // Set logic(1) to specific bit inside specific register
#define clr_bit(reg,bit) reg&=~(1<<bit) 						 // Set logic(0) to specific bit inside specific register
#define tgl_bit(reg,bit) reg^=(1<<bit)  						 // Toggle logic(1) to Logic(0) or vice-versa specific bit inside specific register
#define get_bit(reg,bit) ((reg>>bit)&1) 						 // Set logic(1) to specific bit inside specific register
#define wrt_bit(reg,bit,value) (reg=(value<<bit)|(reg&=~(1<<bit))) // write a value, either 1 or 0 , to specific bit inside specific register
// #define wrt_bit(reg,bit,value) value == 1?(reg|=(1<<bit)):(reg&=~(1<<bit)) // write a value, either 1 or 0 , to a certain bit in a variable


#endif /* BIT_MATH_H_ */
