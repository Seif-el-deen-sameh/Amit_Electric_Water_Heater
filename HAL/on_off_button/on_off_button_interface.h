/*
 * button_interface.h
 *
 *  Created on: Apr 1, 2023
 *      Author: ss210
 */

#ifndef HAL_ON_OFF_BUTTON_INTERFACE_H_
#define HAL_ON_OFF_BUTTON_INTERFACE_H_

void On_Off_Button_Initialize(void);
void On_Off_Button_Enable_pullup(void);
u8 On_Off_Button_Read(void);

#endif /* HAL_BUTTON_BUTTON_INTERFACE_H_ */
