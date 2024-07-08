/*
 * Keypad_cfg.h
 *
 *  Created on: Dec 14, 2023
 *      Author: olege
 */

#ifndef KEYPAD_DRIVERS_KEYPAD_CFG_H_
#define KEYPAD_DRIVERS_KEYPAD_CFG_H_

#define KPD_PORT			DIO_u8PORTC

#define KPD_COLUMN0_PIN		DIO_u8PIN0
#define KPD_COLUMN1_PIN		DIO_u8PIN1
#define KPD_COLUMN2_PIN     DIO_u8PIN2
#define KPD_COLUMN3_PIN     DIO_u8PIN3

#define KPD_ROW0_PIN        DIO_u8PIN4
#define KPD_ROW1_PIN        DIO_u8PIN5
#define KPD_ROW2_PIN        DIO_u8PIN6
#define KPD_ROW3_PIN        DIO_u8PIN7


#define KPD_ARR_VAL			{ {7,8,9,'a'} , {4,5,6,'H'} , {1,2,3,'-'} , {'t',0,'s','+'} }

#endif /*KEYPAD_DRIVERS_KEYPAD_CFG_H_*/
