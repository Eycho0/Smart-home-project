/*
 * sev_seg.c
 *
 *  Created on: Nov 8, 2023
 *      Author: olege
 */
#include "sev_seg.h"

u8 NUMBERS[10] = SEV_SEG_NUMBERS;

ERROR_STATUS SSD_u8SetNumber(SSD* SSDinfo , u8 SSD_u8Copy_Number)
{

	if(SSDinfo->Com_type == SSD_u8Com_Cathode)
	{
		DIO_u8SetPortValue(SSDinfo->Port_num , NUMBERS[SSD_u8Copy_Number]);
	}

	else if(SSDinfo->Com_type == SSD_u8Com_Anode)
	{
		DIO_u8SetPortValue(SSDinfo->Port_num , ~(NUMBERS[(SSD_u8Copy_Number)]));
	}
	return SS_TYPE;
}

ERROR_STATUS SSD_u8Enable(SSD* SSDinfo)
{
	DIO_u8SetPortDirection(SSDinfo->Port_num,DIO_u8PORT_OUTPUT);
	DIO_u8SetPinDirection(SSDinfo->Enable_port,SSDinfo->Enable_pin,DIO_u8PIN_OUTPUT);

	if(SSDinfo->Com_type == SSD_u8Com_Cathode)
	{
		DIO_u8SetPinValue(SSDinfo->Enable_port,SSDinfo->Enable_pin,DIO_u8PIN_LOW);
	}

	if(SSDinfo->Com_type == SSD_u8Com_Anode)
	{
		DIO_u8SetPinValue(SSDinfo->Enable_port,SSDinfo->Enable_pin,DIO_u8PIN_HIGH);
	}
	return SS_TYPE;
}

ERROR_STATUS SSD_u8Disable(SSD* SSDinfo)
{
	if(SSDinfo->Com_type == SSD_u8Com_Cathode)
	{
		DIO_u8SetPinValue(SSDinfo->Enable_port,SSDinfo->Enable_pin,DIO_u8PIN_HIGH);
	}

	if(SSDinfo->Com_type == SSD_u8Com_Anode)
	{
		DIO_u8SetPinValue(SSDinfo->Enable_port,SSDinfo->Enable_pin,DIO_u8PIN_LOW);
	}
	return SS_TYPE;
}
