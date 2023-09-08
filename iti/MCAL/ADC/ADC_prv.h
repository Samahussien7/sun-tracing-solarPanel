

#ifndef MCAL_ADC_ADC_PRV_H_
#define MCAL_ADC_ADC_PRV_H_


#define ADC_PS_2	0b001
#define ADC_PS_4	0b010
#define ADC_PS_8	0b011
#define ADC_PS_16	0b100
#define ADC_PS_64	0b110





#define ADMUX  *((volatile u8*)(0x27))
#define REFS1  7
#define REFS0  6
#define ADLAR  5

#define ADCSRA *((volatile u8*)(0x26))
#define ADEN	7
#define ADSC	6
#define ADATE	5
#define ADIF	4
#define ADIE	3
#define ADPS2	2
#define ADPS1	1
#define ADPS0	0


#define ADCH      *((volatile u8*)(0x25))
#define ADCL      *((volatile u8*)(0x24))
#define ADC	  	  *((volatile u8*)(0x24))

#define SFIOR	  *((volatile u8*)(0x50))

#define ENABLE  1
#define DISABLE 0



#endif /* MCAL_ADC_ADC_PRV_H_ */
