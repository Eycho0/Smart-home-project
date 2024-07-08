/*
 * UART.H
 *
 *  Created on: Feb 2, 2024
 *      Author: olege
 */

#ifndef UART_DRIVERS_UART_H_
#define UART_DRIVERS_UART_H_

#include "../DIO drivers/dio.h"
#include "UART_registers.h"

void UART_vInit(void);

void UART_vSend(u8 Copy_u8Data);

u8 UART_vReceive(void);


#endif /* UART_DRIVERS_UART_H_ */
