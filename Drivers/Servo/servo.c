/*
 * servo.c
 *
 *  Created on: May 2, 2024
 *      Author: olege
 */

#include "servo.h"

void servo_rotate(u16 angle) {

	u16 duty_cycle = ((angle * 1000)) / 180 + 1000;

    OCR1A = duty_cycle;

    _delay_ms(50);
}
