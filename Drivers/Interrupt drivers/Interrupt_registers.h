/*
 * Interrupt_registers.h
 *
 *  Created on: Jan 23, 2024
 *      Author: olege
 */

#ifndef INTERRUPT_DRIVERS_INTERRUPT_REGISTERS_H_
#define INTERRUPT_DRIVERS_INTERRUPT_REGISTERS_H_

#define MCUCR 			*((volatile pu8)0x55)
#define MCUCR_ISC11 	3
#define MCUCR_ISC10 	2
#define MCUCR_ISC01 	1
#define MCUCR_ISC00 	0

#define MCUCSR 			*((volatile pu8)0x54)
#define MCUCSR_ISC2		6

#define GICR			*((volatile pu8)0x5B)
#define GICR_INT1		7
#define GICR_INT0		6
#define GICR_INT2		5

#define SREG			*((volatile pu8)0x5F)
#define SREG_I			7

#endif /* INTERRUPT_DRIVERS_INTERRUPT_REGISTERS_H_ */
