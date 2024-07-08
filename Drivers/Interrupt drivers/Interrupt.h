/*
 * Interrupt.h
 *
 *  Created on: Jan 23, 2024
 *      Author: olege
 */

#ifndef INTERRUPT_DRIVERS_INTERRUPT_H_
#define INTERRUPT_DRIVERS_INTERRUPT_H_

#include "Interrupt_registers.h"
#include "../DIO drivers/dio.h"

void GIE_vEnable(void);
void GIE_vDisable(void);

void EIE_vINT0Init(void (*Copy_CallBackFun)(void));

void EIE_vINT1Init(void);

void EIE_vINT2Init(void);

#endif /* INTERRUPT_DRIVERS_INTERRUPT_H_ */
