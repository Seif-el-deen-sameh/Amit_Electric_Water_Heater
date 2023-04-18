/*
 * DIO_private.h
 *
 * Created: 1/6/2023 10:49:21 AM
 *  Author: ss210
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "DIO_Private.h"
#include "bit_math.h"
#include "DIO_Interface.h"
#include "DIO_Configuration.h"
#include <util/delay.h>

void DIO_SetPin_Direction(DIO_PORT port,u8 pin ,DIO_State state);
void DIO_SetPin_Value(DIO_PORT port, u8 pin, DIO_Status status);
void DIO_TogglePin_Value(DIO_PORT port,u8 pin);
u8 DIO_ReadPin_Value(DIO_PORT port,u8 pin);
void u8_Activate_Pullup(DIO_PORT port,u8 pin);

void DIO_SetPort_Direction(DIO_PORT port,DIO_State state);
void DIO_SetPort_Value(DIO_PORT port, u8 value);
void DIO_TogglePort_Value(DIO_PORT port);
u8 DIO_ReadPort_Value(DIO_PORT port);
void DIO_Port_Activate_Pullup(DIO_PORT port);


#endif /* DIO_PRIVATE_H_ */
