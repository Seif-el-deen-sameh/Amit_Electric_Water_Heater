/*
 * led1_interface.h
 *
 *  Created on: Mar 28, 2023
 *      Author: ss210
 */

#ifndef HAL_HEATER_RELAY_INTERFACE_H_
#define HAL_HEATER_RELAY_INTERFACE_H_

#include "heater_relay_private.h"

void Heater_Relay_Initialize(void);
void Heater_Relay_ON(void);
void Heater_Relay_OFF(void);
void Heater_Relay_TGL(void);
#endif /* HAL_HEATING_ELEMENT_LED_HEATING_ELEMENT_LED_INTERFACE_H_ */
