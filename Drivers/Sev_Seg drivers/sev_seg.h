/*
 * sev_seg.h
 *
 *  Created on: Nov 7, 2023
 *      Author: olege
 */

#ifndef SEV_SEG_H_
#define SEV_SEG_H_

//order of pins 0bABCDEFGH. {zero,			one,			two,		three,		four,		five,		six,		seven			,eight,			nine}

#define SEV_SEG_NUMBERS		{0b11111110 , 0b01100000 , 0b11011010 , 0b11110010 , 0b01100110 , 0b10110110 , 0b10111110 , 0b11100000 , 0b11111110 , 0b11110110}

#include "../DIO drivers/dio.h"

typedef struct
{
	u8 Numbers[10];
	u8 Com_type;
	u8 Port_num;
	u8 Enable_port;
	u8 Enable_pin;
}SSD;

#define SSD_u8Com_Cathode	0
#define SSD_u8Com_Anode		1

ERROR_STATUS SSD_u8SetNumber(SSD* SSDinfo , u8 SSD_u8Copy_Number);

ERROR_STATUS SSD_u8Enable(SSD* SSDinfo);

ERROR_STATUS SSD_u8Disable(SSD* SSDinfo);


#define SSD_u8_zero		0
#define SSD_u8_one		1
#define SSD_u8_two 		2
#define SSD_u8_three 	3
#define SSD_u8_four 	4
#define SSD_u8_five 	5
#define SSD_u8_six		6
#define SSD_u8_seven 	7
#define SSD_u8_eight 	8
#define SSD_u8_nine 	9

#endif /* SEV_SEG_H_ */
