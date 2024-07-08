/*
 * EEPROM.c
 *
 *  Created on: May 1, 2024
 *      Author: olege
 */
#include "EEPROM.h"

void EEPROM_vWrite(u32 Address, u8 data) {
    while(EECR & (1<<EEWE)); // Wait for previous write to complete
    EEAR = Address; // Set EEPROM address
    EEDR = data; // Set data to write
    EECR = ( (EECR|(1<<EEMWE)) | (1<<EEWE)) ; // Set EEMWE to enable EEPROM writes
}

u8	EEPROM_u8Read(u32 Adress)
{
	while(EECR&(1<<EEWE));
	EEAR = Adress;
	EECR |= (1<<EERE);

	return EEDR;
}
