/*
 * SPI_registers.h
 *
 *  Created on: Feb 2, 2024
 *      Author: olege
 */

#ifndef SPI_DRIVERS_SPI_REGISTERS_H_
#define SPI_DRIVERS_SPI_REGISTERS_H_

#define	SPDR				*((volatile u8*)0x2F)

#define	SPSR				*((volatile u8*)0x2E)
#define	SPSR_SPIF			7
#define	SPSR_SPI2X			0

#define	SPCR				*((volatile u8*)0x2D)
#define	SPCR_SPIE			7
#define	SPCR_SPE			6
#define	SPCR_MSTR			4
#define	SPCR_SPR1			1
#define	SPCR_SPR0			0

#endif /* SPI_DRIVERS_SPI_REGISTERS_H_ */
