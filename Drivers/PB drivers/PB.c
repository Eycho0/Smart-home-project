/*
 * PB.c
 *
 *  Created on: Nov 6, 2023
 *      Author: olege
 */
#include "PB.h"

ERROR_STATUS PB_u8init(u8 Copy_u8PB_port , u8 Copy_u8PB_pin){

	return DIO_u8SetPinValue(Copy_u8PB_port,Copy_u8PB_pin,DIO_u8PIN_HIGH);
}


ERROR_STATUS PB_u8GET_STATE(u8 PB_u8Port , u8 PB_u8Pin , u8 PB_u8Pulltype , pu8 PB_pu8Value)
{
	u8 value;

	DIO_u8GetPinValue(PB_u8Port , PB_u8Pin , &value);
	if (value==PB_u8UnPressed)
	{
		while (value==PB_u8UnPressed)
		{
		 DIO_u8GetPinValue(PB_u8Port , PB_u8Pin , &value);
		}
		* PB_pu8Value = PB_u8UnPressed;
		return PB_NPRESSED;
	}

	else if (value==PB_u8Pressed)
	{
		while (value==PB_u8Pressed)
		{
		 DIO_u8GetPinValue(PB_u8Port , PB_u8Pin , &value);
		}
		* PB_pu8Value = PB_u8Pressed;
		return PB_PRESSED;
	}

	return PB_VALUE;
}
