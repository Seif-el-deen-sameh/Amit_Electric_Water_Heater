/*
 * ADC_interface.h
 *
 *  Created on: Apr 4, 2023
 *      Author: ss210
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

#include "ADC_private.h"
#include "std_types.h"

void ADC_enable(void);
void ADC_disable(void);
void ADC_initalize(void);
void ADC_start_conversion(void);
void ADC_enable_interrupt(void);
void ADC_disable_interrupt(void);
void ADC_enable_auto_trigger(void);
void ADC_disable_auto_trigger(void);
void ADC_channel_select(channel ch);
void ADC_store_dircetion(store_dircetion dir);
void ADC_Vref_Mode(Reference_Selection ref);
void ADC_set_divion_factor(Division_Factor value);
void ADC_read_value_async(u8*copy_value);
void ADC_Auto_trigger_source(trigger_source trigger);
void ADC_ISR(void(*copy_ptrtofunction)(void));


#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
