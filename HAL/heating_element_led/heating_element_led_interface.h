/*
 * Heating_Element_Led_interface.h
 *
 *  Created on: Mar 28, 2023
 *      Author: ss210
 */

#ifndef HAL_HEATING_ELEMENT_LED_INTERFACE_H_
#define HAL_HEATING_ELEMENT_LED_INTERFACE_H_

#include "heating_element_led_private.h"

void Heating_Element_Led_Initialize(void);
void Heating_Element_Led_ON(void);
void Heating_Element_Led_OFF(void);
void Heating_Element_Led_TGL(void);
#endif /* HAL_HEATING_ELEMENT_LED_HEATING_ELEMENT_LED_INTERFACE_H_ */
