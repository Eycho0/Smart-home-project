/*

 * DIO.C
 *
 *  Created on: Nov 5, 2023
 *      Author: olege
 */
#include "dio.h"

ERROR_STATUS DIO_u8SetPinDirection(u8 Copy_u8port_num , u8 Copy_u8pin_num , u8 Copy_u8direction)
{
	if(Copy_u8pin_num > DIO_u8PIN7)
	{
		return DIO_PIN;
	}

	else if(Copy_u8direction == DIO_u8PIN_INPUT)
		{
			switch(Copy_u8port_num)
			{
			case DIO_u8PORTA : CLR_BIT(DDRA, Copy_u8pin_num); break;
			case DIO_u8PORTB : CLR_BIT(DDRB, Copy_u8pin_num); break;
			case DIO_u8PORTC : CLR_BIT(DDRC, Copy_u8pin_num); break;
			case DIO_u8PORTD : CLR_BIT(DDRD, Copy_u8pin_num); break;
			default : return DIO_PORT ; break;
			}
		}

	else if(Copy_u8direction == DIO_u8PIN_OUTPUT)
		{
		switch(Copy_u8port_num)
		{
			case DIO_u8PORTA : SET_BIT(DDRA, Copy_u8pin_num); break;
			case DIO_u8PORTB : SET_BIT(DDRB, Copy_u8pin_num); break;
			case DIO_u8PORTC : SET_BIT(DDRC, Copy_u8pin_num); break;
			case DIO_u8PORTD : SET_BIT(DDRD, Copy_u8pin_num); break;
			default : return DIO_PORT; break;
		}
		}

	else if(Copy_u8direction > DIO_u8PIN_OUTPUT || Copy_u8direction < DIO_u8PIN_INPUT )
		{
			return DIO_DIR;
		}

	return DIO_OK;
}

ERROR_STATUS DIO_u8SetPortDirection(u8 Copy_u8port_num ,u8 Copy_u8direction)
{
	if(Copy_u8port_num > DIO_u8PORTD)
	{
		return DIO_PORT;
	}

	switch(Copy_u8port_num)
	{
		case DIO_u8PORTA : DDRA = Copy_u8direction; break;
	    case DIO_u8PORTB : DDRB = Copy_u8direction; break;
	    case DIO_u8PORTC : DDRC = Copy_u8direction; break;
	    case DIO_u8PORTD : DDRD = Copy_u8direction; break;
	    default: return DIO_DIR;
	}

	return DIO_OK;
}

ERROR_STATUS DIO_u8SetPinValue(u8 Copy_u8port_num , u8 Copy_u8pin_num , u8 Copy_u8value)
{
	if(Copy_u8pin_num > DIO_u8PIN7)
	{
		return DIO_PIN;
	}

	if(Copy_u8value == DIO_u8PIN_LOW)
		{
		switch(Copy_u8port_num)
		{
		case DIO_u8PORTA : CLR_BIT(PORTA,Copy_u8pin_num); break;
		case DIO_u8PORTB : CLR_BIT(PORTB,Copy_u8pin_num); break;
		case DIO_u8PORTC : CLR_BIT(PORTC,Copy_u8pin_num); break;
		case DIO_u8PORTD : CLR_BIT(PORTD,Copy_u8pin_num); break;
		default : return DIO_PORT; break;
		}
		}

	else if(Copy_u8value == DIO_u8PIN_HIGH)
		{
		switch(Copy_u8port_num)
		{
		case DIO_u8PORTA : SET_BIT(PORTA,Copy_u8pin_num); break;
		case DIO_u8PORTB : SET_BIT(PORTB,Copy_u8pin_num); break;
		case DIO_u8PORTC : SET_BIT(PORTC,Copy_u8pin_num); break;
		case DIO_u8PORTD : SET_BIT(PORTD,Copy_u8pin_num); break;
		default : return DIO_PORT; break;
		}
		}

		return DIO_OK;
}

ERROR_STATUS DIO_u8SetPortValue(u8 Copy_u8port_num ,u8 Copy_u8value)
{

	switch(Copy_u8port_num)
	{
		case DIO_u8PORTA : PORTA = Copy_u8value; break;
	    case DIO_u8PORTB : PORTB = Copy_u8value; break;
	    case DIO_u8PORTC : PORTC = Copy_u8value; break;
	    case DIO_u8PORTD : PORTD = Copy_u8value; break;
	    default: return DIO_PORT;
	}

	return DIO_OK;
}

ERROR_STATUS DIO_u8GetPinValue(u8 Copy_u8port_num , u8 Copy_u8pin_num , pu8 Copy_pu8value)
{

	if ((Copy_pu8value != NULL) && (Copy_u8pin_num > DIO_u8PIN7))
	{
		return DIO_PIN;
	}

	switch(Copy_u8port_num)
		{
			case DIO_u8PORTA : *Copy_pu8value = GET_BIT(PINA , Copy_u8pin_num); break;
		    case DIO_u8PORTB : *Copy_pu8value = GET_BIT(PINB , Copy_u8pin_num); break;
		    case DIO_u8PORTC : *Copy_pu8value = GET_BIT(PINC , Copy_u8pin_num); break;
		    case DIO_u8PORTD : *Copy_pu8value = GET_BIT(PIND , Copy_u8pin_num); break;
		    default: return DIO_PORT;
		}

	return DIO_OK;
}

ERROR_STATUS DIO_u8TogglePinValue(u8 Copy_u8port_num , u8 Copy_u8pin_num)
{
	if(Copy_u8pin_num > DIO_u8PIN7)
	{
		return DIO_PIN;
	}

	switch(Copy_u8port_num)
	{
		case DIO_u8PORTA : TOGGLE_BIT(PORTA , Copy_u8pin_num); break;
	    case DIO_u8PORTB : TOGGLE_BIT(PORTB , Copy_u8pin_num); break;
	    case DIO_u8PORTC : TOGGLE_BIT(PORTC , Copy_u8pin_num); break;
	    case DIO_u8PORTD : TOGGLE_BIT(PORTD , Copy_u8pin_num); break;
	    default: return DIO_PORT;
	}

	return DIO_OK;
}
