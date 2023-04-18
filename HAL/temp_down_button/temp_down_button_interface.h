/*
 * button_interface.h
 *
 *  Created on: Apr 1, 2023
 *      Author: ss210
 */

#ifndef HAL_TEMP_DOWN_BUTTON_INTERFACE_H_
#define HAL_TEMP_DOWN_BUTTON_INTERFACE_H_

void Temp_Down_Button_Initialize(void);
void Temp_Down_Button_Enable_pullup(void);
u8 Temp_Down_Button_Read(void);

#endif /* HAL_BUTTON_BUTTON_INTERFACE_H_ */
