/*
 * UART.c
 *
 *  Created on: Feb 2, 2024
 *      Author: olege
 */
#include "UART.h"

void UART_vInit(void)
{
	UCSRC = 0b10000110;
	UBRRL = 51;
	SET_BIT(UCSRB,UCSRB_TXEN);
	SET_BIT(UCSRB,UCSRB_RXEN);
}

void UART_vSend(u8 Copy_u8Data)
{
	while((GET_BIT(UCSRA,UCSRA_UDRE)==0));
	UDR = Copy_u8Data;
}

u8 UART_vReceive(void)
{
	while((GET_BIT(UCSRA,UCSRA_RXC)==0));
	return UDR;
}
