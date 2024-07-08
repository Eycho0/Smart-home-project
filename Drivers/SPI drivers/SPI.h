/*
 * SPI.h
 *
 *  Created on: Feb 2, 2024
 *      Author: olege
 */

#ifndef SPI_DRIVERS_SPI_H_
#define SPI_DRIVERS_SPI_H_

#include "../DIO drivers/dio.h"
#include "SPI_registers.h"

void SPI_vInitMaster(void);

void SPI_vInitSlave(void);

u8 	SPI_u8Transceive(u8 Copy_u8Data);

#endif /* SPI_DRIVERS_SPI_H_ */
