/*
 * PB.h
 *
 *  Created on: Nov 6, 2023
 *      Author: olege
 */

#ifndef PB_DRIVERS_PB_H_
#define PB_DRIVERS_PB_H_

#include "../DIO drivers/DIO.h"

//Button state
#define PB_u8Pressed 1
#define PB_u8UnPressed 0

ERROR_STATUS PB_u8init(u8 Copy_u8PB_port , u8 Copy_u8PB_pin); //initialize Pushbutton to be input

ERROR_STATUS PB_u8GET_STATE(u8 PB_u8Port , u8 PB_u8Pin , u8 PB_u8Pulltype , pu8 PB_pu8Value); //read the pushbutton state (high or low)

#endif /* PB_DRIVERS_PB_H_ */
