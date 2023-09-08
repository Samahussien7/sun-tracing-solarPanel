

#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"

#include "ADC_Init.h"
#include "ADC_prv.h"
#include "ADC_confg.h"


void (*ADC_callback)(void);

void MADC_voidIntit(){
/*	 // Set reference voltage to AVCC and left-adjust result
	ADMUX = (1 << REFS0);

	// Enable ADC and set ADC prescaler to 64 (for 8MHz clock)
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1);


*/

	//Data adjustment
	CLR_BIT(ADMUX, ADLAR);
	// Select Prescaler
	ADCSRA = (ADCSRA& 0xF8) | ADC_PS_64 ;  //125khz   < 200 khz
	// Auto trigger Enable
	CLR_BIT(ADCSRA, ADATE);
	// Reference Voltage
#if ADC_ReF_VOLT == AVCC
	CLR_BIT(ADMUX, REFS1);
	SET_BIT(ADMUX, REFS0);
#elif ADC_ReF_VOLT == Internal_Ref
	SET_BIT(ADMUX, REFS0);
#elif ADC_ReF_VOLT == AREF
	CLR_BIT(ADMUX, REFS1);
	CLR_BIT(ADMUX, REFS0);
#else
#error "Please select the correct reference"
#endif



	// INT Enable/disable
#if ADC_Intrrupt_ENABLE== DISABLE
	CLR_BIT(ADCSRA, ADIE);
#elif ADC_Intrrupt_ENABLE== ENABLE
	SET_BIT(ADCSRA, ADIE);
#else
#error "Please select the correct Mode"
#endif


	// Enable ADC
	SET_BIT(ADCSRA, ADEN);

}
// Polling

u16 MADC_u16AnalogRead(u8 A_u8ChannelNo){

	/*// Select channel
	  ADMUX = (ADMUX & 0xF0) | (A_u8ChannelNo & 0x0F) ;
	  // start Conversion
	  SET_BIT(ADCSRA, ADSC);
	  // Poll on Flag

	  while(ADCSRA & (1<<ADSC) );
	  // Clear flag
	 // CLR_BIT(ADCSRA, ADIF);

	  return ADC;*/

// Select channel
  ADMUX = (ADMUX & 0xE0) | (A_u8ChannelNo & 0x07) ;
  // start Conversion
  SET_BIT(ADCSRA, ADSC);
  // Poll on Flag
  while(get_bit(ADCSRA, ADIF) !=1 );
  // Clear flag
  CLR_BIT(ADCSRA, ADIF);

  return ADC;

}

// INT_ADC

void MADC_voidStartConversion(u8 A_u8ChannelNo){

	 // Select channel
	  ADMUX = (ADMUX & 0xE0) | (A_u8ChannelNo & 0x07) ;
	  // start Conversion
	  SET_BIT(ADCSRA, ADSC);

}

u16 MADC_u16GetADCData (void)
{

	 return ADC;
}


void MADC_voidSetCallBack 	  (void (*A_FuncPtr)(void)){

	ADC_callback = A_FuncPtr;
}

/*ADC_ISR*/

void __vector_16(void) 		__attribute__((signal));

void __vector_16(void){

	ADC_callback();
}


