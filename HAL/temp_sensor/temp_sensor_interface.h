/*
 * temp_sensor_interface.h
 *
 *  Created on: Apr 7, 2023
 *      Author: ss210
 */

#ifndef HAL_TEMP_SENSOR_TEMP_SENSOR_INTERFACE_H_
#define HAL_TEMP_SENSOR_TEMP_SENSOR_INTERFACE_H_
#include "bit_math.h"

void Temp_Sensor_Initialize(void);
void Temp_Sensor_Enable_pullup(void);
u8 Temp_Sensor_Read(void);

#endif /* HAL_TEMP_SENSOR_TEMP_SENSOR_INTERFACE_H_ */
