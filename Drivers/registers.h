/*
 * registers.c
 *
 *  Created on: Nov 4, 2023
 *      Author: olege
 */
#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "Data_Types.h"

//  PORTA registers

#define PORTA 	*((volatile pu8)0x3B)
#define DDRA 	*((volatile pu8)0x3A)
#define PINA 	*((volatile pu8)0x39)

//  PORTB registers

#define PORTB 	*((volatile pu8)0x38)
#define DDRB 	*((volatile pu8)0x37)
#define PINB 	*((volatile pu8)0x36)

//  PORTC registers

#define PORTC 	*((volatile pu8)0x35)
#define DDRC 	*((volatile pu8)0x34)
#define PINC 	*((volatile pu8)0x33)

//  PORTD registers

#define PORTD 	*((volatile pu8)0x32)
#define DDRD 	*((volatile pu8)0x31)
#define PIND 	*((volatile pu8)0x30)

#endif /*REGISTERS_H_*/
