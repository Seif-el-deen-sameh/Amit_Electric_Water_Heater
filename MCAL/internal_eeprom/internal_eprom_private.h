/*
 * internal_eprom_private.h
 *
 *  Created on: Apr 17, 2023
 *      Author: ss210
 */

#ifndef MCAL_INTERNAL_EEPROM_INTERNAL_EPROM_PRIVATE_H_
#define MCAL_INTERNAL_EEPROM_INTERNAL_EPROM_PRIVATE_H_

#include "std_types.h"

#define EEARH  ( *(volatile u8*)0x3F)
#define EEARL  ( *(volatile u8*)0x3E)
#define EEAR  ( *(volatile u16*)0x3E)
#define EEDR   ( *(volatile u8*)0x3D)
#define EECR   ( *(volatile u8*)0x3C)
#define SPMCR  ( *(volatile u8*)0x57)

#endif /* MCAL_INTERNAL_EEPROM_INTERNAL_EPROM_PRIVATE_H_ */
