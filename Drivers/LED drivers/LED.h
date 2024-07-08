/*
 * LED.h
 *
 *  Created on: Nov 5, 2023
 *      Author: olege
 */

#ifndef LED_DRIVERS_LED_H_
#define LED_DRIVERS_LED_H_

#include "../DIO drivers/dio.h"

ERROR_STATUS LED_u8init(u8 LED_u8port , u8 LED_u8pin); //initialize LED

ERROR_STATUS LED_u8On(u8 LED_u8port , u8 LED_pin); //Turn on LED

ERROR_STATUS LED_u8Off(u8 LED_u8port , u8 LED_pin); //Turn off LED

ERROR_STATUS LED_u8Toggle(u8 LED_u8port , u8 LED_pin); //Toggle the LED

ERROR_STATUS LED_u8Blink(u8 LED_u8port, u8 LED_u8pin , u8 u8Time_off , u8 u8Time_on); //Turn led on and off for set amount of time

#endif /* LED_DRIVERS_LED_H_ */
