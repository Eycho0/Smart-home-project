/*
 * LED.c
 *
 *  Created on: Nov 5, 2023
 *      Author: olege
 */
#include "LED.h"

ERROR_STATUS LED_u8init(u8 LED_u8port , u8 LED_u8pin)
{
	DIO_u8SetPinDirection(LED_u8port, LED_u8pin , DIO_u8PIN_OUTPUT);

	return DIO_OK;
}

ERROR_STATUS LED_u8On(u8 LED_u8port , u8 LED_u8pin)
{
	DIO_u8SetPinValue(LED_u8port, LED_u8pin, DIO_u8PIN_HIGH);

	return DIO_OK;
}

ERROR_STATUS LED_u8Off(u8 LED_u8port , u8 LED_u8pin)
{

	DIO_u8SetPinValue(LED_u8port, LED_u8pin, DIO_u8PIN_LOW);

	return DIO_OK;
}

ERROR_STATUS LED_u8Toggle(u8 LED_u8port , u8 LED_u8pin)
{
	DIO_u8TogglePinValue(LED_u8port , LED_u8pin);

	return DIO_OK;
}

ERROR_STATUS LED_u8blink(u8 LED_u8port, u8 LED_u8pin , u8 u8time_off , u8 u8time_on)
{
	DIO_u8SetPinValue(LED_u8port, LED_u8pin, DIO_u8PIN_HIGH);
	_delay_ms(u8time_on);
	DIO_u8SetPinValue(LED_u8port, LED_u8pin, DIO_u8PIN_LOW);
	_delay_ms(u8time_off);

	return DIO_OK;
}
