/*
 * std-types.h
 *
 *  Created on: Oct 7, 2023
 *      Author: olege
 */

#ifndef DATA_TYPES_H_
#define DATA_TYPES_H_

typedef unsigned char 	 u8;
typedef unsigned char* 	pu8;
typedef signed char* 	ps8;
typedef signed char 	 s8;
typedef unsigned short 	u16;
typedef unsigned short* pu16;
typedef signed short s16;
typedef signed short* ps16;
typedef unsigned int u32;
typedef unsigned int* pu32;
typedef signed int s32;
typedef signed int* ps32;
typedef  float f32;
typedef  float* pf32;
typedef  double d64;
typedef  double* pd64;

//DIO error types

typedef enum {
	DIO_OK,
	DIO_PORT,
	DIO_PIN,
	DIO_DIR,
	PB_PRESSED,
	PB_NPRESSED,
	PB_VALUE,
	SS_TYPE,
}ERROR_STATUS;

#define	NULL 		0
#define OK			1
#define	NOK			2
#define BUSY_FUNC	3


#define NULL_POINTER ((void *)0)

#endif /* DATA_TYPES_H_ */
/*
u8 heart[8]={
		  0B00000,
		  0B11011,
		  0B11111,
		  0B11111,
		  0B01110,
		  0B00100,
		  0B00000,
		  0B00000

};

u8 snake[8]={

		  0B11000,
		  0B11000,
		  0B01111,
		  0B00001,
		  0B11111,
		  0B10000,
		  0B11111,
		  0B00000
};
*/
/*
	u8 alef1[8]={
	  0B00100,
	  0B00100,
	  0B00100,
	  0B00100,
	  0B00000,
	  0B00110,
	  0B01100,
	  0B00000
	  };

	u8 ya2[8]={
	  0B00000,
	  0B00000,
	  0B00001,
	  0B00001,
	  0B11111,
	  0B00000,
	  0B01010,
	  0B00000
	  };

	u8 alef2[8]={
	  0B00001,
	  0B00001,
	  0B00001,
	  0B00001,
	  0B00001,
	  0B00000,
	  0B00000,
	  0B00000
	  };
	 u8 dal[8]={
	  0B00000,
	  0B00001,
	  0B00001,
	  0B00001,
	  0B01111,
	  0B00000,
	  0B00000,
	  0B00000
	  };
	    B00100,
	u8 arrow[8]=
	{
	  0B01110,
	  0B11111,
	  0B00100,
	  0B00100,
	  0B00100,
	  0B00100,
	  0B00000
	}

	u8 coloun[8]=
	{
	0B00000,
	0B00100,
	0B00100,
	0B00000,
	0B00000,
	0B00100,
	0B00100,
	0B00000
	}
void myname(u8 x, u8 y){
CLCD_vSendSpecialChar(dal,1,x,y);
CLCD_vSendSpecialChar(alef2,2,x,y+1);
CLCD_vSendSpecialChar(ya2,3,x,y+2);
CLCD_vSendSpecialChar(alef1,4,x,y+3);
}
*/
