
#include "../LIB/std_types.h"
#include "../LIB/bit_math.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/ADC/ADC_Init.h"
#include "../MCAL/Timer/PWM_Init.h"

#define F_CPU 8000000UL // Assuming an 8MHz clock frequency

#include <util/delay.h>
#define LDR_THRESHOLD 50
#define SERVO_MIN   0
#define SERVO_MAX   180
#define LDR1_PIN    0 // ADC0 pin (Analog input 0) for the first LDR
#define LDR2_PIN    1 // ADC1 pin (Analog input 1) for the second LDR

u16  map(u16 x ,u16 in_min,u16 in_max, u16 out_min, u16 out_max);


int main()
{

	//MGIR_voidEnable();
	MADC_voidIntit();
   MDIO_voidSetPinDirection(PORTD, PIN5, HIGH);

    MTIMR1_voidTimer1Init();
    MTIMR1_voidSetICR(2000);
    u16 val1, val2;
    u16 pos =1500;           //1500    90
   MTIMR1_voidTimer1SetCompMatchA(pos);

    while (1)
    {
    	MADC_voidStartConversion(LDR1_PIN);
    	MADC_voidStartConversion(LDR2_PIN);

    	val1=MADC_u16AnalogRead(LDR1_PIN);
    	val2=MADC_u16AnalogRead(LDR2_PIN);

    	val1=map(val1,0,1023,0,180);
    	val2=map(val2,0,1023,0,180);


	  if (val1 > (val2 + LDR_THRESHOLD))
	  {
				if (pos < SERVO_MAX)
					pos++;
				if (pos > SERVO_MAX) {
					pos = SERVO_MAX;}
				pos=map(pos,0,180,1000,2000);
				MTIMR1_voidTimer1SetCompMatchA(pos);


	  }
	  else if (val2 > (val1 + LDR_THRESHOLD))
	  {
				if (pos > SERVO_MIN)
					pos--;
				if (pos < SERVO_MIN) {
					pos = SERVO_MIN;}
				pos=map(pos,0,180,1000,2000);
				MTIMR1_voidTimer1SetCompMatchA(pos);

	  }


    }

    return 0;
}

u16  map(u16 x ,u16 in_min,u16 in_max, u16 out_min, u16 out_max){
	// Ensure that x is within the input range

    if (x < in_min) {
        x = in_min;
    }
    if (x > in_max) {
        x = in_max;
    }

	 // Calculate the mapped value

	return (x-in_min)*(out_max-out_min)/(in_max-in_min) + out_min;
}

