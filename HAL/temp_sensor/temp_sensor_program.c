/*
 * temp_sensor_program.c
 *
 *  Created on: Apr 7, 2023
 *      Author: ss210
 */

#include "temp_sensor_private.h"
#include "temp_sensor_interface.h"
#include "ADC_private.h"

void Temp_Sensor_Initialize(void){
	DIO_SetPin_Direction(Temp_Sensor_PRT,Temp_Sensor,Temp_Sensor_IN);
	//DIO_ActivatePin_PullUp(Temp_Sensor_PRT,Temp_Sensor);
	/*ADC_Vref_Mode(_AVCC);
	ADC_channel_select(0);
	ADC_enable_interrupt();*/
	ADC_initalize();
}
void Temp_Sensor_Enable_pullup(void){

}
u8 Temp_Sensor_Read(void){

return 0;
}
