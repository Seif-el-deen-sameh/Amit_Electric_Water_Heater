/*
 * main.c
 *
 *  Created on: Mar 21, 2023
 *      Author: ss210
 */

#include "main.h"
#define F_CPU 16000000u
//interrupt functions initialization
void Temperature_up(void);
void Temperature_down(void);
void System_status(void);
void Sensor_reading(void);
//Global Variables initialization
volatile u8  Temperature=60;
volatile u8  counts=0;
volatile u8  status=0;
volatile s8  Sensor_value=0;
volatile u8  Sensor_value_raw=0;
volatile s16 Temperature_avg=0;

int main(){
	//System I/O initialization
	Heating_Element_Led_Initialize();
	Temp_Up_Button_Initialize();
	Temp_Down_Button_Initialize();
	On_Off_Button_Initialize();
	Heater_Relay_Initialize();
	Cooler_Relay_Initialize();
	Temp_Sensor_Initialize();
	S_seg_Initialize(cathode);
	//Set functions to be executed when corresponding interrupt is triggered
	EXTI_voidSetCallBack(INT0,System_status);
	EXTI_voidSetCallBack(INT1,Temperature_up);
	EXTI_voidSetCallBack(INT2,Temperature_down);
	ADC_ISR(Sensor_reading);
	//Enable global interrupt
	Global_interrupt_enable;

	while(1){
		while(status==1){
			ADC_start_conversion();
			//Print Temperature value on 7 segment
			S_seg_print_two_segments(Temperature);
		}
	}
	return 0;
}

void System_status(void){
	//Change status based on previous value
	status==0?status++:status--;
	//reset average value of readings
	Temperature_avg=0;
	//read stored Temperature in atmega32 internal EEPROM
	Temperature=EEPROM_read(address);
	//if internal EEPROM gets corrupted set default value
	Temperature>75?Temperature=60:Temperature<35?Temperature=60:Temperature;
	//shutdown the system if the state is 0
	if(status==0){
	Heater_Relay_OFF();
	Cooler_Relay_OFF();
	Heating_Element_Led_OFF();
	S_seg_clear(cathode);
	//Write the set Temperature in atmega32 internal EEPROM
	EEPROM_write(address,Temperature);
	}
	//Clear 7 segment display
	S_seg_clear(cathode);
}

void Temperature_up(void)
{
	//Clear 7 segment display
	S_seg_clear(cathode);
	//add Temperature if Temperature is smaller than 75oC
	Temperature=Temperature<75?Temperature+5:Temperature;
	//Write the set Temperature in atmega32 internal EEPROM
	EEPROM_write(address,Temperature);
	//Display the set Temperature on 7 segment display is system is off ( Temperature configuration mode )
	if(status==0){
		for(u8 i=0;i<50;i++){
			S_seg_print_two_segments(Temperature);
		}
	}
	//Clear 7 segment display
	S_seg_clear(cathode);
}

void Temperature_down(void)
{
	//Clear 7 segment display
	S_seg_clear(cathode);
	//remove Temperature if Temperature is larger than 35oC
	Temperature=Temperature>35?Temperature-5:Temperature;
	//Write the set Temperature in atmega32 internal EEPROM
	EEPROM_write(address,Temperature);
	//Display the set Temperature on 7 segment display is system is off ( Temperature configuration mode )
	if(status==0){
		for(u8 i=0;i<50;i++){
			S_seg_print_two_segments(Temperature);
		}
	}
	//Clear 7 segment display
	S_seg_clear(cathode);
}

void Sensor_reading(void){
	_delay_ms(100);
	//Acquire Sensor value after conversion
	Sensor_value_raw = ADCH;
	//convert Sensor value after conversion to Temperature
	Sensor_value = (Sensor_value_raw * 0.8) - 55;
	//add current Temperature to total Temperature values
	Temperature_avg=Temperature_avg+Sensor_value;
	//if system did 10 counts ( 0 to 9 )
	if(counts==9){
		//Divide total Temperature values by 10 to calculate average Temperature value
		Temperature_avg=Temperature_avg/10;
		//Turn cooler on and heater off if average Temperature value is bigger than set Temperature value
		if(Temperature_avg>(Temperature+5)){
			Heater_Relay_OFF();
			Cooler_Relay_ON();
			Heating_Element_Led_ON();
		}
		//Turn heater on and cooler off if average Temperature value is bigger than set Temperature value
		else if(Temperature_avg<(Temperature+5)){
			Heater_Relay_ON();
			Cooler_Relay_OFF();
			Heating_Element_Led_TGL();
		}
		//reset the average value calculation variables
		counts-=9;
		Temperature_avg=0;
	}
	else
	{
		//add new Temperature value to the calculation sequence
		counts++;
	}


}
