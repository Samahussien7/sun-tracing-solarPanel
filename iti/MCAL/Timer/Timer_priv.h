/*
 * Timer_priv.h
 *
 *  Created on: Aug 27, 2023
 *      Author: ProBook G7
 */

#ifndef MCAL_TIMER_TIMER_PRIV_H_
#define MCAL_TIMER_TIMER_PRIV_H_

#define OCR0			*((volatile u8*)(0x5C))
#define OCR1AH			*((volatile u8*)(0x4B))
#define OCR1AL			*((volatile u8*)(0x4A))
#define OCR1BH			*((volatile u8*)(0x49))
#define OCR1BL			*((volatile u8*)(0x48))
#define ICR1H    		*((volatile u8*)(0x47))
#define ICR1L  		    *((volatile u8*)(0x46))
#define OCR2			*((volatile u8*)(0x43))

#define TIMSK			*((volatile u8*)(0x59))
#define TIFR			*((volatile u8*)(0x58))
#define TCCR0			*((volatile u8*)(0x53))
#define TCCR1A			*((volatile u8*)(0x4F))
#define TCCR1B			*((volatile u8*)(0x4E))
#define TCCR2			*((volatile u8*)(0x45))

#define TCNT0			*((volatile u8*)(0x52))
#define TCNT1H			*((volatile u8*)(0x4D))
#define TCNT1L			*((volatile u8*)(0x4C))
#define TCNT2			*((volatile u8*)(0x44))



#define TIMER0				0
#define TIMER1				1
#define TIMER2				2


#define  TCCR1A  	 *((volatile u8*)(0x4F))
#define  TCCR1B   	 *((volatile u8*)(0x4E))

#define  TCNT1   	 *((volatile u16*)(0x4C))
#define  OCR1A   	 *((volatile u16*)(0x4A))
#define  OCR1B   	 *((volatile u16*)(0x48))
#define  ICR1    	 *((volatile u16*)(0x46))

/* TCCR1A Bits */
#define   COM1A1  			  7
#define   COM1A0   			  6
#define   COM1B1    		  5
#define   COM1B0   			  4
#define   FOC1A    			  3
#define   FOC1B   			  2
#define   WGM11   			  1
#define   WGM10    			  0

/* TCCR1B Bits */
#define   ICNC1     		7
#define   ICES1   		    6
#define   WGM13     		4
#define   WGM12     		3
#define   CS12      		2
#define   CS11     		    1
#define   CS10     		    0


#define COM00				 4
#define COM01				 5
#define WGM00				 6
#define WGM01 				 3

#define COM20 				 4
#define COM21 				 5
#define WGM20 				 6
#define WGM21 	 			 3

// Prescaler options
#define NO_CLOCK  			 (u8)0x00
#define NO_PRESCALING	  	 (u8)0x01
#define PRESCALER_8      	 (u8)0x02
#define PRESCALER_64      	 (u8)0x03
#define PRESCALER_256     	 (u8)0x04
#define PRESCALER_1024   	 (u8)0x05
#define EXTCLK_FALLING   	 (u8)0x06
#define EXTCLK_RISING    	 (u8)0x07

// Modes of operation
#define MODE_NORMAL	          (u8)1
#define MODE_PWM		      (u8)2
#define MODE_CTC		      (u8)3
#define MODE_FASTPWM	      (u8)4


#define NonPWM_NORMAL  		  (u8)1
#define NonPWM_TOGGLE  		  (u8)2
#define NonPWM_CLEAR   		  (u8)3
#define NonPWM_SET      	  (u8)4

#define FastPWM_NORMAL  	  (u8)1
#define FastPWM_CLEAR   	  (u8)2
#define FastPWM_SET     	  (u8)3
#endif /* MCAL_TIMER_TIMER_PRIV_H_ */
