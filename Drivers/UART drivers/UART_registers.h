/*
 * UART_registers.h
 *
 *  Created on: Feb 2, 2024
 *      Author: olege
 */

#ifndef UART_DRIVERS_UART_REGISTERS_H_
#define UART_DRIVERS_UART_REGISTERS_H_

#define UDR				*((volatile u8*)0x2C)

#define UCSRA			*((volatile u8*)0x2B)
#define UCSRA_RXC		7
#define UCSRA_TXC		6
#define UCSRA_UDRE		5

#define UCSRB			*((volatile u8*)0x2A)
#define UCSRB_RXCIE		7
#define UCSRB_TXCIE		6
#define UCSRB_UDRIE		5
#define UCSRB_RXEN		4
#define UCSRB_TXEN		3


#define UCSRC			*((volatile u8*)0x40)
#define UCSRC_URSEL		7
#define UCSRC_UMSEL		6
#define UCSRC_UPM1		5
#define UCSRC_UPM0		4

#define UBRRH			*((volatile u8*)0x40)
#define UBRRH_URSEL		7

#define UBRRL	*((volatile u8*)0x29)


#endif /* UART_DRIVERS_UART_REGISTERS_H_ */
