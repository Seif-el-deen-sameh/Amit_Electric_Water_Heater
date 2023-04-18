/*
 * button_interface.h
 *
 *  Created on: Apr 1, 2023
 *      Author: ss210
 */

#ifndef HAL_TEMP_UP_BUTTON_INTERFACE_H_
#define HAL_TEMP_UP_BUTTON_INTERFACE_H_

void BTN0_Initialize(void);
void BTN0_Enable_pullup(void);
u8 BTN0_Read(void);

#endif /* HAL_BUTTON_BUTTON_INTERFACE_H_ */
