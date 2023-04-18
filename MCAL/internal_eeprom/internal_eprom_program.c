/*
 * internal_eprom_program.c
 *
 *  Created on: Apr 17, 2023
 *      Author: ss210
 */
#include "internal_eeprom/internal_eprom_interface.h"
#include "internal_eeprom/internal_eprom_private.h"
#include "bit_math.h"
#include "std_types.h"

void EEPROM_write(u16 Address,u8 Data){
	/* Wait for completion of previous write */
	while(EECR & (1<<1));
	while(SPMCR & (1<<0));
	/* Set up address and data registers */
	EEAR = Address;
	EEDR = Data;
	/* Write logical one to 2 */
	EECR |= (1<<2);
	/* Start eeprom write by setting 1 */
	EECR |= (1<<1);
}
u8 EEPROM_read(u16 Address){
	/* Wait for completion of previous write */
	while(EECR & (1<<1));
	/* Set up address register */
	EEAR = Address;
	/* Start eeprom read by writing 0 */
	EECR |= (1<<0);
	/* Return data from data register */
	return EEDR;
}

