/*
 * Interrupt.c
 *
 *  Created on: Jan 23, 2024
 *      Author: olege
 */
#include "Interrupt.h"

static void (*INT0_CallBackFun)(void);

void GIE_vEnable(void)
{
	SET_BIT(SREG,SREG_I);
}

void GIE_vDisable(void)
{
	CLR_BIT(SREG,SREG_I);
}

void EIE_vINT0Init(void (*Copy_CallBackFun)(void))
{
	SET_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);
	if(Copy_CallBackFun != NULL_POINTER)
	{
		INT0_CallBackFun = Copy_CallBackFun;
	}
	SET_BIT(GICR,GICR_INT0);
}

void EIE_vINT1Init(void)
{
	SET_BIT(MCUCR,MCUCR_ISC11);
	CLR_BIT(MCUCR,MCUCR_ISC10);

	SET_BIT(GICR,GICR_INT1);
}

void EIE_vINT2Init(void)
{
	SET_BIT(MCUCSR,MCUCSR_ISC2);

	SET_BIT(GICR,GICR_INT1);
}


void __vector_1 (void) __attribute__ ((signal));
void __vector_1 (void)
{
	INT0_CallBackFun();
}
