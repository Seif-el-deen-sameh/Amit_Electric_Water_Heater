/*
 * led1_interface.h
 *
 *  Created on: Mar 28, 2023
 *      Author: ss210
 */

#ifndef HAL_COOLER_RELAY_INTERFACE_H_
#define HAL_COOLER_RELAY_INTERFACE_H_

#include "cooler_relay_private.h"

void Cooler_Relay_Initialize(void);
void Cooler_Relay_ON(void);
void Cooler_Relay_OFF(void);
void Cooler_Relay_TGL(void);
#endif /* HAL_HEATING_ELEMENT_LED_HEATING_ELEMENT_LED_INTERFACE_H_ */
