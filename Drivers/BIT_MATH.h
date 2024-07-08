/*
 * BIT_MATH.h
 *
 *  Created on: Nov 7, 2023
 *      Author: olege
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(VAR,BIT_NO)		(VAR|= (1<<BIT_NO))
#define CLR_BIT(VAR,BIT_NO)		(VAR&= ~(1<<BIT_NO))
#define TOGGLE_BIT(VAR,BIT_NO)	(VAR^= (1<<BIT_NO))
#define GET_BIT(VAR,BIT_NO)		(VAR&(1<<BIT_NO))

#endif /* BIT_MATH_H_ */
