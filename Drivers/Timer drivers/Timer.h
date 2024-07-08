/*
 * Timer0.h
 *
 *  Created on: Feb 1, 2024
 *      Author: olege
 */

#ifndef TIMER_DRIVERS_TIMER_H_
#define TIMER_DRIVERS_TIMER_H_

#include "Timer_cfg.h"
#include "Timer_private.h"
#include "Timer_registers.h"
#include "../DIO drivers/dio.h"

void Timer0_vInit(void);

void Timer1_vInit(void);

void init_PWM(void);

u8 Timer0_u8SetCallBack (void (*Copy_pvCallBackFun)(void));

void Timer1_vSetChannelACompareMatch(u16 Copy_u16CompareMatch);
void Timer1_vSetICR(u16 Copy_u16TOP);

#endif /* TIMER_DRIVERS_TIMER_H_ */
