/*
 * Timer0.c
 *
 *  Created on: Feb 1, 2024
 *      Author: olege
 */
#include "Timer.h"
#include "../DIO drivers/dio.h"

static void (*TIMER0_pvCallBackFunc)(void)= NULL;

void Timer0_vInit(void)
{
	/*Set to CTC mode*/
	SET_BIT(TCCR0,TCCR0_WGM01);
	CLR_BIT(TCCR0,TCCR0_WGM00);

	/*Compare match Interrupt enable*/
	SET_BIT(TIMSK,TIMSK_OCIE0);


	/*Set compare match value*/
	OCR0=250;

	/*Set prescaler value*/
	SET_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	SET_BIT(TCCR0,TCCR0_CS02);


}

u8 Timer0_u8SetCallBack (void (*Copy_pvCallBackFun)(void))
{
	u8 Local_u8ErrorState= OK;

	if(Copy_pvCallBackFun != NULL)
	{
		TIMER0_pvCallBackFunc = Copy_pvCallBackFun;
	}

	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}

	return Local_u8ErrorState;
}

void Timer1_vSetChannelACompareMatch(u16 Copy_u16CompareMatch)
{
	OCR1A=Copy_u16CompareMatch;
}
void Timer1_vSetICR(u16 Copy_u16TOP)
{
	ICR1 = Copy_u16TOP;
}

void Timer1_vInit(void)
{
	SET_BIT(TCCR1A,TCCR1A_COM1A1);
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);

	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);

	TCCR1B &= PRESCALER_MASK;
	TCCR1B |= DIV_BY_8;

}



void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if(TIMER0_pvCallBackFunc != NULL)
	{
		TIMER0_pvCallBackFunc();
	}
}
