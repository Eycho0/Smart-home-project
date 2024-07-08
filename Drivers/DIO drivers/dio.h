/*
 * dio.h
 *
 *  Created on: Nov 5, 2023
 *      Author: olege
 */

#ifndef DIO_H_
#define DIO_H_

#include <util/delay.h>

#include "../registers.h"
#include "../BIT_MATH.h"
#include "../Data_Types.h"

//Driver MACROS
#define DIO_u8PORTA 		0
#define DIO_u8PORTB 		1
#define DIO_u8PORTC 		2
#define DIO_u8PORTD 		3

//direction defines
#define DIO_u8PIN_INPUT 	0
#define DIO_u8PIN_OUTPUT 	1

//value defines
#define DIO_u8PIN_LOW 		0
#define DIO_u8PIN_HIGH 		1

//pin defines
#define DIO_u8PIN0 			0
#define DIO_u8PIN1 			1
#define DIO_u8PIN2 			2
#define DIO_u8PIN3 			3
#define DIO_u8PIN4 			4
#define DIO_u8PIN5 			5
#define DIO_u8PIN6 			6
#define DIO_u8PIN7 			7

//Port direction option
#define DIO_u8PORT_OUTPUT 	0xff
#define DIO_u8PORT_INPUT 	0x00

//Port value option
#define DIO_u8PORT_HIGH 	0xff
#define DIO_u8PORT_LOW 		0x00

//Driver prototypes

/***************************************************************************************
 DISCRIPTION:
  	  	  	 set a DIO pin direction
 PARAMETERS:
  	  	  	 [1] DIO_u8PORTA...DIO_u8PORTD
 	 	 	 [2] DIO_u8PIN0...DIO_u8PIN7
 	 	 	 [3] DIO_u8PIN_INPUT/DIO_u8PIN_OUTPUT
 RETURN:
 	 	 	 ERROR_STATUS(DIO_PIN/DIO_PORT/DIO_DIR/DIO_OK)
*****************************************************************************************/
ERROR_STATUS DIO_u8SetPinDirection(u8 Copy_u8port_num , u8 Copy_u8pin_num , u8 Copy_u8direction); //set pin direction (INPUT / OUTPUT)
ERROR_STATUS DIO_u8SetPortDirection(u8 Copy_u8port_num ,u8 Copy_u8direction); //set port direction (INPUT / OUTPUT)

ERROR_STATUS DIO_u8SetPinValue(u8 Copy_u8port_num , u8 Copy_u8pin_num , u8 Copy_u8value); //set pin value (HIGH / LOW)
ERROR_STATUS DIO_u8SetPortValue(u8 Copy_u8port_num ,u8 Copy_u8value); //set port value (HIGH / LOW)

ERROR_STATUS DIO_u8GetPinValue(u8 Copy_u8port_num , u8 Copy_u8pin_num , pu8 Copy_pu8value); //read data from pin

ERROR_STATUS DIO_u8TogglePinValue(u8 Copy_u8port_num , u8 Copy_u8pin_num); //toggle pin value

#endif /* DIO_H_ */
