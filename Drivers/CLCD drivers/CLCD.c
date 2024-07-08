/*
 * CLCD.c
 *
 *  Created on: Nov 23, 2023
 *      Author: olege
 */
#include "CLCD.h"
#include "CLCD_cfg.h"

void CLCD_vInit(void)
{

	DIO_u8SetPortDirection(CLCD_DATA_PORT,DIO_u8PORT_OUTPUT);

	//wait for more than 30ms to raise voltage
	_delay_ms(45);

	#if CLCD_MODE == CLCD_8BitMode

	//function set command
	CLCD_vSend_Command(0b00111000);

	//display on/off command display enable/ no cursor / blink off
	CLCD_vSend_Command(0b00001100);

	//clear display command
	CLCD_vSend_Command(0b00000001);

	#elif CLCD_MODE == CLCD_4BitMode
	CLCD_vSend_Command(0X03);

	//function set command
	CLCD_vSend_Command(0X02);
	CLCD_vSend_Command(0X28);

	//display on/off command display enable/ no cursor / blink off
	CLCD_vSend_Command(0X08);
	CLCD_vSend_Command(0X01);

	//clear display command
	CLCD_vSend_Command(0X06);
	CLCD_vSend_Command(0X0C);

	#endif
}

void CLCD_vSend_Command(u8 Copy_u8Command)
{
	#if CLCD_MODE == CLCD_8bitMode

	//set RS low for command
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);
	//set RW low for write
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	//send command to data pins
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Command);

	//send enable pulse
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);

	#elif CLCD_MODE == CLCD_4BitMode

	//send higher nibble of command to data pins

	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Command&0XF0);
	//set RS low for command
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);
	//set RW low for write
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);


	//send enable pulse
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
	_delay_us(200);
	//send lower nibble of command to data pins

	DIO_u8SetPortValue(CLCD_DATA_PORT,(Copy_u8Command<<4)&0XF0);
	//set RS low for command
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);
	//set RW low for write
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	//send enable pulse
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);

	_delay_ms(2);
	#endif



}
void CLCD_vSend_Data(u8 Copy_u8Data)
{
	#if CLCD_MODE == CLCD_8BitMode

	//set RS high for data
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);
	//set RW low for write
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	//send data to data pins
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);

	//send enable pulse
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);

	#elif CLCD_MODE == CLCD_4BitMode

	//send higher nibble of command to data pins

	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data&0XF0);
	//set RS high for data
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);
	//set RW low for write
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);


	//send enable pulse
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);

	//send lower nibble of command to data pins

	DIO_u8SetPortValue(CLCD_DATA_PORT,(Copy_u8Data<<4)&0XF0);
	//set RS high for data
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);
	//set RW low for write
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);



	//send enable pulse
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);

	_delay_ms(2);
	#endif
}

u16 currentRow=0,currentCol=0;
void CLCD_vMoveToNextLine()
{

	if (++currentRow >= CLCD_ROWS)
	{
		currentRow = 0; // If at the last row, move back to the first row
	}
	if (currentRow == 1)
	{
		CLCD_vSend_Command(0xC0); // Move to the second line
	}
	else
	{
		CLCD_vSend_Command(0X1);
		CLCD_vSend_Command(0x80); // Move to the first line
	}
	currentCol = 0; // Reset column position to start of the line
}

void CLCD_vSendString(const u8 *str) {
    u8 charCount = 0;

    // Loop until the end of the string ('\0' character) or LCD boundary is reached
    while (*str != '\0' && charCount < 32) { // Limit to 32 characters (16x2 LCD)
        // Check if the current character count exceeds the first line limit (16 characters)
        if (charCount == 16) {
            // Move to the second line
            CLCD_vSend_Command(0xC0); // Set DDRAM address to the beginning of the second line
        }
        // Send each character of the string
        CLCD_vSend_Data(*str);
        // Move to the next character
        str++;
        charCount++;
    }
}

void CLCD_vGoToXY(u8 Copy_u8Yposition, u8 Copy_u8Xposition)
{

	if (Copy_u8Xposition >= 2) {
		Copy_u8Xposition = 1; // Limit y position to last row
	}
	if (Copy_u8Yposition >= 16) {
		Copy_u8Yposition = 15; // Limit x position to last column
	}
	u8 Local_u8Adress;


	if(Copy_u8Xposition==0){
		Local_u8Adress=Copy_u8Yposition;
	}
	else if(Copy_u8Xposition==1){
		Local_u8Adress=Copy_u8Yposition+0x40;
	}
	CLCD_vSend_Command(SET_BIT(Local_u8Adress,7));
}


void CLCD_vSendSpecialChar(pu8 Copy_pu8Pattern , u8 Copy_pu8PatternNumber, u8 Copy_u8XPosition, u8 Copy_u8YPosition)
{
	u8 Local_u8CGRAM_Adress=0,Local_u8Iterator;

	Local_u8CGRAM_Adress = Copy_pu8PatternNumber * 8;

	CLCD_vSend_Command(Local_u8CGRAM_Adress+64);

	for(Local_u8Iterator=0; Local_u8Iterator<8 ; Local_u8Iterator++)
	{
		CLCD_vSend_Data(Copy_pu8Pattern[Local_u8Iterator]);
	}

	CLCD_vGoToXY(Copy_u8XPosition,Copy_u8YPosition);

	CLCD_vSend_Data(Copy_pu8PatternNumber);
}

static u16 CLCD_u16GetLengh(u16 Copy_u16Number)
{
	u16 Length = (Copy_u16Number == 0? 1 :0);
	while(Copy_u16Number>0)
	{
		Length++;
		Copy_u16Number/=10;
	}
	return Length;
}
void CLCD_vSendNumber(u16 Copy_u8Number)
{
	u8 str[16];
	u16 i=0;
	u16 length = CLCD_u16GetLengh(Copy_u8Number);

	while(length > 0)
	{
		u8 digit = Copy_u8Number%10;
		str[i] = digit + '0';
		Copy_u8Number /= 10;
		length--;
		i++;
	}

	str[i] = '\0';

	u16 start = 0;
	u16 end = i - 1;
	while (start < end)
	{
		u8 temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
	u16 j=0;
	while(str[j] != '\0')
	{
		/*if(currentCol>=CLCD_COLS )
		{
			CLCD_vMoveToNextLine();
		}
		*/
		if (str[j]==0)
			CLCD_vSend_Data('0');
		else
		CLCD_vSend_Data(str[j]);
		j++;
		currentCol++;
	}
}


void CLCD_vClearScreen() {
    CLCD_vSend_Command(0x01); // Send clear screen command
}
