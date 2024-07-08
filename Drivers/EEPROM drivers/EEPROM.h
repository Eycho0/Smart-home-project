/*
 * EEPROM.h
 *
 *  Created on: May 1, 2024
 *      Author: olege
 */

#ifndef EEPROM_DRIVERS_EEPROM_H_
#define EEPROM_DRIVERS_EEPROM_H_

#include "../DIO drivers/dio.h"
#include "EEPROM_registers.h"

void EEPROM_vWrite(u32 Adress, u8 data);
u8	EEPROM_u8Read(u32 Adress);

#endif /* EEPROM_DRIVERS_EEPROM_H_ */
