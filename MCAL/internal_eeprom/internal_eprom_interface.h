/*
 * internal_eprom_interface.h
 *
 *  Created on: Apr 17, 2023
 *      Author: ss210
 */

#ifndef MCAL_INTERNAL_EEPROM_INTERNAL_EPROM_INTERFACE_H_
#define MCAL_INTERNAL_EEPROM_INTERNAL_EPROM_INTERFACE_H_
#include "std_types.h"
void EEPROM_write(u16 Address,u8 Data);
u8 EEPROM_read(u16 Address);

#endif /* MCAL_INTERNAL_EEPROM_INTERNAL_EPROM_INTERFACE_H_ */
