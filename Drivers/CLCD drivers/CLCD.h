/*
 * CLCD.h
 *
 *  Created on: Nov 23, 2023
 *      Author: olege
 */
#ifndef CLCD_DRIVERS_CLCD_H_
#define CLCD_DRIVERS_CLCD_H_

#include "../DIO drivers/dio.h"
#include "CLCD_cfg.h"

#define CLCD_8BitMode	0

#define CLCD_4BitMode	1

#define CLCD_ROWS 2
#define CLCD_COLS 16

void CLCD_vSend_Command(u8 Copy_u8Command);

void CLCD_vSend_Data(u8 Copy_u8Data);

void CLCD_vInit(void);

void CLCD_vSendString(const u8 *Copy_pu8String);

void CLCD_vGoToXY(u8 Copy_u8Xposition, u8 Copy_u8Yposition);

void CLCD_vSendSpecialChar(pu8 Copy_pu8Pattern , u8 Copy_pu8PatternNumber, u8 Copy_u8XPosition,u8 Copy_u8YPosition);

void CLCD_vSendNumber(u16 Copy_u8Number);

void CLCD_vClearScreen();


#endif /* CLCD_DRIVERS_CLCD_H_ */
