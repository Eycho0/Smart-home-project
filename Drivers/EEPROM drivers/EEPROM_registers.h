/*
 * EEPROM_registers.h
 *
 *  Created on: May 1, 2024
 *      Author: olege
 */

#ifndef EEPROM_DRIVERS_EEPROM_REGISTERS_H_
#define EEPROM_DRIVERS_EEPROM_REGISTERS_H_

#define EEAR		*((volatile u8*)0x3E)
#define EEDR		*((volatile u8*)0x3D)

#define EECR		*((volatile u8*)0x3C)
#define EERE		0
#define EEWE		1
#define EEMWE		2
#define EERIE		3


#endif /* EEPROM_DRIVERS_EEPROM_REGISTERS_H_ */
