/*
 * Timer0_registers.h
 *
 *  Created on: Feb 1, 2024
 *      Author: olege
 */

#ifndef TIMER_DRIVERS_TIMER_REGISTERS_H_
#define TIMER_DRIVERS_TIMER_REGISTERS_H_

#define TCCR0			*((volatile u8*)0x53)		//Timer 0 control register
#define	TCCR0_CS00		0						//Clock prescaler bit 0
#define	TCCR0_CS01		1						//Clock prescaler bit 1
#define	TCCR0_CS02		2						//Clock prescaler bit 2
#define	TCCR0_WGM00		6						//Mode select bit 0
#define	TCCR0_WGM01		3						//Mode select bit 1
#define	TCCR0_COM00		4						//Compare output mode bit 0
#define	TCCR0_COM01		5						//Compare output mode bit 0

#define TCNT0			*((volatile u8*)0x52)		//Timer compare register

#define OCR0			*((volatile u8*)0x5C)		//Output compare register

#define	TIMSK			*((volatile u8*)0x59)		//Interrupt mask register
#define	TIMSK_TOIE0		0						//Timer overflow enable
#define	TIMSK_OCIE0		1						//Timer On compare match enable
#define	TIMSK_TICIE1	5


#define	TIMFR			*((volatile u8*)0x58)		//Interrupt flag register
#define	TIMFR_TOV0		0						//On compare flag
#define	TIMFR_OCF0		1						//Overflow flag
#define TIMFR_ICF1		5

#define TCCR1A			*((volatile u8*)0x4F)		//Timer 0 control register
#define TCCR1A_WGM10	0
#define TCCR1A_WGM11	1
#define TCCR1A_COM1A0	6
#define TCCR1A_COM1A1	7

#define TCCR1B			*((volatile u8*)0x4E)		//Timer 0 control register
#define TCCR1B_CS10		0
#define TCCR1B_CS11		1
#define TCCR1B_CS12		2
#define TCCR1B_WGM12	3
#define TCCR1B_WGM13	4

#define OCR1A			*((volatile u16*)0x4A)

#define ICR1			*((volatile u16*)0x46)

#define PRESCALER_MASK	0b11111000;
#define	DIV_BY_8		2
#endif /* TIMER_DRIVERS_TIMER_REGISTERS_H_ */
