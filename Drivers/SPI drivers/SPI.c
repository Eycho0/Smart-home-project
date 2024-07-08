/*
 * SPI.c
 *
 *  Created on: Feb 2, 2024
 *      Author: olege
 */
#include "SPI.h"

void SPI_vInitMaster(void)
{
	SET_BIT(SPCR,SPCR_MSTR);

	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);

	SET_BIT(SPCR,SPCR_SPE);
}

void SPI_vInitSlave(void)
{
	CLR_BIT(SPCR,SPCR_MSTR);

	SET_BIT(SPCR,SPCR_SPE);
}
u8 	SPI_u8Transceive(u8 Copy_u8Data)
{
	/*Send data*/
	SPDR = Copy_u8Data;

	/*WAIT FOR TRANSFER*/
	while(GET_BIT(SPSR,SPSR_SPIF)==0);

	/*Get the exchanged data*/
	return SPDR;
}
