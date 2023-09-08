/*
 * PWM_Init.h
 *
 *  Created on: Aug 27, 2023
 *      Author: ProBook G7
 */

#ifndef MCAL_TIMER_PWM_INIT_H_
#define MCAL_TIMER_PWM_INIT_H_

#include "../../LIB/bit_math.h"
#include "../../LIB/std_types.h"

void MTIMR1_voidTimer1Init();
void MTIMR1_voidSetICR(u16 A_u16value);
void MTIMR1_voidTimer1SetCompMatchA(u16 A_u16value);
void MTIMR1_voidTimer1SetCompMatchB(u16 A_u16value);

#endif /* MCAL_TIMER_PWM_INIT_H_ */
