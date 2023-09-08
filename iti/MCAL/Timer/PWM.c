/*
 * PWM.c
 *
 *  Created on: Aug 27, 2023
 *      Author: ProBook G7
 */
#include "../Timer/PWM_Init.h"
#include "../Timer/Timer_priv.h"

void MTIMR1_voidTimer1Init()
{
	/* Select Mode : fast pwm */
	CLR_BIT(TCCR1A , WGM10);
	SET_BIT(TCCR1A , WGM11);
	SET_BIT(TCCR1B , WGM12);
	SET_BIT(TCCR1B , WGM13);

	/* Choose non inverting mode */
	SET_BIT(TCCR1A , COM1A1);
	CLR_BIT(TCCR1A , COM1A0);

	/* Choose Prescaler to 64
	 * Every tick will take 8 us
	CLR_BIT(TCCR1B, TCCR1B_CS10);
	CLR_BIT(TCCR1B, TCCR1B_CS11);
	SET_BIT(TCCR1B, TCCR1B_CS12);
*/

	/* Choose Prescaler to 8
	/ * Every tick will take 1 us

	 */
	CLR_BIT(TCCR1B , CS10);
	SET_BIT(TCCR1B , CS11);
	CLR_BIT(TCCR1B , CS12);
}

void MTIMR1_voidSetICR(u16 A_u16value)
{
	ICR1 =A_u16value;
}

void MTIMR1_voidTimer1SetCompMatchA(u16 A_u16value)
{
	OCR1A = A_u16value;

}

void MTIMR1_voidTimer1SetCompMatchB(u16 A_u16value)
{
	OCR1B = A_u16value;
}
