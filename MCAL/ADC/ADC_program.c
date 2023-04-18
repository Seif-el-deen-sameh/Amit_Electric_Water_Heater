/*
 * ADC_program.c
 *
 *  Created on: Apr 4, 2023
 *      Author: ss210
 */
#include "ADC_configuration.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "bit_math.h"
#include "std_types.h"
void(*ptr5)(void);
u8* adc_generic_reading=0;
void ADC_enable(void){
	set_bit(ADCSRA,ADCSRA_ADEN);
}
void ADC_disable(void){
	clr_bit(ADCSRA,ADCSRA_ADEN);
}
void ADC_start_conversion(void){
	set_bit(ADCSRA,ADCSRA_ADSC);
}
void ADC_enable_interrupt(void){
	set_bit(ADCSRA,ADCSRA_ADIE);
}
void ADC_disable_interrupt(void){
	clr_bit(ADCSRA,ADCSRA_ADIE);
}
void ADC_enable_auto_trigger(void){
	set_bit(ADCSRA,ADCSRA_ADATE);
}
void ADC_disable_auto_trigger(void){
	clr_bit(ADCSRA,ADCSRA_ADATE);
}
void ADC_store_dircetion(store_dircetion dir){
	switch(dir)
	{
		case _left:
		clr_bit(ADMUX,ADMUX_ADLAR);
		break;
		case _right:
		set_bit(ADMUX,ADMUX_ADLAR);
		break;
	}
}
void ADC_Vref_Mode(Reference_Selection ref){
		switch(ref)
		{
			case _AREF:
			clr_bit(ADMUX,ADMUX_REFS0);
			clr_bit(ADMUX,ADMUX_REFS1);
			break;
			case _AVCC:
			set_bit(ADMUX,ADMUX_REFS0);
			clr_bit(ADMUX,ADMUX_REFS1);
			break;
			case _Internal:
			set_bit(ADMUX,ADMUX_REFS0);
			set_bit(ADMUX,ADMUX_REFS1);
			break;
		}

}
void ADC_channel_select(channel ch){
	ADMUX &= 0b1110000;
	ADMUX |= ch;
}
void ADC_set_divion_factor(Division_Factor value){
			switch(value)
			{
				case __2:
				clr_bit(ADCSRA,ADCSRA_ADPS0);
				clr_bit(ADCSRA,ADCSRA_ADPS1);
				clr_bit(ADCSRA,ADCSRA_ADPS2);
				break;
				case __4:
				clr_bit(ADCSRA,ADCSRA_ADPS0);
				set_bit(ADCSRA,ADCSRA_ADPS1);
				clr_bit(ADCSRA,ADCSRA_ADPS2);
				break;
				case __8:
				set_bit(ADCSRA,ADCSRA_ADPS0);
				set_bit(ADCSRA,ADCSRA_ADPS1);
				clr_bit(ADCSRA,ADCSRA_ADPS2);
				break;
				case __16:
				clr_bit(ADCSRA,ADCSRA_ADPS0);
				clr_bit(ADCSRA,ADCSRA_ADPS1);
				set_bit(ADCSRA,ADCSRA_ADPS2);
				break;
				case __32:
				set_bit(ADCSRA,ADCSRA_ADPS0);
				clr_bit(ADCSRA,ADCSRA_ADPS1);
				set_bit(ADCSRA,ADCSRA_ADPS2);
				break;
				case __64:
				clr_bit(ADCSRA,ADCSRA_ADPS0);
				set_bit(ADCSRA,ADCSRA_ADPS1);
				set_bit(ADCSRA,ADCSRA_ADPS2);
				break;
				case __128:
				set_bit(ADCSRA,ADCSRA_ADPS0);
				set_bit(ADCSRA,ADCSRA_ADPS1);
				set_bit(ADCSRA,ADCSRA_ADPS2);
				break;
			}
}
void ADC_Auto_trigger_source(trigger_source trigger){
switch(trigger)
{
	case Free_Running:
	clr_bit(SFIOR,SFIOR_ADTS0);
	clr_bit(SFIOR,SFIOR_ADTS1);
	clr_bit(SFIOR,SFIOR_ADTS2);
	break;
	case Analog_Comparator:
	set_bit(SFIOR,SFIOR_ADTS0);
	clr_bit(SFIOR,SFIOR_ADTS1);
	clr_bit(SFIOR,SFIOR_ADTS2);
	break;
	case External_Interrupt_0:
	clr_bit(SFIOR,SFIOR_ADTS0);
	set_bit(SFIOR,SFIOR_ADTS1);
	clr_bit(SFIOR,SFIOR_ADTS2);
	break;
	case Timer0_Compare_Match:
	set_bit(SFIOR,SFIOR_ADTS0);
	set_bit(SFIOR,SFIOR_ADTS1);
	clr_bit(SFIOR,SFIOR_ADTS2);
	break;
	case Timer0_Overflow:
	clr_bit(SFIOR,SFIOR_ADTS0);
	clr_bit(SFIOR,SFIOR_ADTS1);
	set_bit(SFIOR,SFIOR_ADTS2);
	break;
	case Timer1_Compare_Match_B:
	set_bit(SFIOR,SFIOR_ADTS0);
	clr_bit(SFIOR,SFIOR_ADTS1);
	set_bit(SFIOR,SFIOR_ADTS2);
	break;
	case Timer1_Overflow:
	clr_bit(SFIOR,SFIOR_ADTS0);
	set_bit(SFIOR,SFIOR_ADTS1);
	set_bit(SFIOR,SFIOR_ADTS2);
	break;
	case Timer1_Capture_Event:
	set_bit(SFIOR,SFIOR_ADTS0);
	set_bit(SFIOR,SFIOR_ADTS1);
	set_bit(SFIOR,SFIOR_ADTS2);
	break;
}
}
void ADC_initalize(void){

	set_bit(ADMUX,ADMUX_REFS0);
	clr_bit(ADMUX,ADMUX_REFS1);

	//clr_bit(ADMUX,ADMUX_REFS0);
	//clr_bit(ADMUX,ADMUX_REFS1);

	set_bit(ADMUX,ADMUX_ADLAR);
	set_bit(ADCSRA,ADCSRA_ADPS0);
	set_bit(ADCSRA,ADCSRA_ADPS1);
	set_bit(ADCSRA,ADCSRA_ADPS2);
	set_bit(ADCSRA,ADCSRA_ADEN);
	set_bit(ADCSRA,ADCSRA_ADIE);
	//set_bit(ADCSRA,ADCSRA_ADATE);
	ADMUX &= 0b11100000;
	ADMUX |= 0b00000000;
	//set_bit(SFIOR,6);
	//set_bit(SFIOR,7);
	/*ADC_Vref_Mode(_AVCC);
	ADC_store_dircetion(_left);
	ADC_set_divion_factor(__128);
	ADC_enable();*/
}
void ADC_read_value_async(u8* copy_value){
	//ADC_enable_interrupt();
	set_bit(ADCSRA,ADCSRA_ADIE);
	//set_bit(Sreg,7);
	//ADC_channel_select(ch0);
	ADMUX &= 0b11100000;
	ADMUX |= 0b00000000;
	adc_generic_reading = copy_value;
	//ADC_start_conversion();
	set_bit(ADCSRA,ADCSRA_ADSC);

}
void ADC_ISR(void(*copy_ptrtofunction)(void))
{

	ptr5=copy_ptrtofunction;
}

void __vector_16(void)  __attribute__((signal));
void __vector_16(void){
	//*adc_generic_reading = ADCH;
	ptr5();
}
