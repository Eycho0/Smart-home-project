/*
 * Keypad.h
 *
 *  Created on: Dec 14, 2023
 *      Author: olege
 */

#ifndef KEYPAD_DRIVERS_KEYPAD_H_

#include "../DIO drivers/dio.h"
#include "Keypad_cfg.h"

#define KPD_NOT_PRESSED		0xff

u8 KPD_u8GetPressedKey(void);
void KPD_vKPDInit(void);


#endif /* KEYPAD_DRIVERS_KEYPAD_H_ */
