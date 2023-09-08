
#ifndef MCAL_ADC_ADC_INIT_H_
#define MCAL_ADC_ADC_INIT_H_

#define  Channel_0	0
#define  Channel_1	1

/* Polling ADC  */
void MADC_voidIntit();
u16 MADC_u16AnalogRead(u8 A_u8ChannelNo);

/* Interrupt based APIs */

void MADC_voidStartConversion (u8 A_u8ChannelNo);
u16  MADC_u16GetADCData       (void);
void MADC_voidSetCallBack 	  (void (*A_FuncPtr)(void));

#endif /* MCAL_ADC_ADC_INIT_H_ */
