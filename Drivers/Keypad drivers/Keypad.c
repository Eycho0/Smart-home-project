/*
 * Keypad.c
 *
 *  Created on: Dec 14, 2023
 *      Author: olege
 */

#include "Keypad.h"

void KPD_vKPDInit(void)
{
	DIO_u8SetPortValue(KPD_PORT, DIO_u8PORT_HIGH);


	DIO_u8SetPinDirection(KPD_PORT, KPD_ROW0_PIN, DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(KPD_PORT, KPD_ROW1_PIN, DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(KPD_PORT, KPD_ROW2_PIN, DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(KPD_PORT, KPD_ROW3_PIN, DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(KPD_PORT, KPD_COLUMN0_PIN, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(KPD_PORT, KPD_COLUMN1_PIN, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(KPD_PORT, KPD_COLUMN2_PIN, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(KPD_PORT, KPD_COLUMN3_PIN, DIO_u8PIN_OUTPUT);

}

u8 KPD_u8GetPressedKey(void)
{
	u8 Local_u8PressedKey=KPD_NOT_PRESSED, Local_u8ColumnIndex , Local_u8RowIndex , Local_u8PinState;
	u8 Local_u8ColumnArr[4] = { KPD_COLUMN0_PIN, KPD_COLUMN1_PIN, KPD_COLUMN2_PIN, KPD_COLUMN3_PIN};
	u8 Local_u8RowArr[4] = { KPD_ROW0_PIN, KPD_ROW1_PIN, KPD_ROW2_PIN, KPD_ROW3_PIN};
	u8 Local_u8KPDArr[4][4] = KPD_ARR_VAL;


	for(Local_u8ColumnIndex=0 ;Local_u8ColumnIndex < 4 ;Local_u8ColumnIndex++ )
	{
		//Activate current column
		DIO_u8SetPinValue(KPD_PORT,Local_u8ColumnArr[Local_u8ColumnIndex],DIO_u8PIN_LOW);

		for(Local_u8RowIndex=0 ;Local_u8RowIndex < 4 ;Local_u8RowIndex++)
		{
			//read current row
			DIO_u8GetPinValue(KPD_PORT,Local_u8RowArr[Local_u8RowIndex],&Local_u8PinState);

			//check if pin is pressed
			if(DIO_u8PIN_LOW == Local_u8PinState)
			{
				//Busy waiting until key is released
				while(DIO_u8PIN_LOW == Local_u8PinState)
				{
					DIO_u8GetPinValue(KPD_PORT,Local_u8RowArr[Local_u8RowIndex],&Local_u8PinState);
				}

				Local_u8PressedKey = Local_u8KPDArr[Local_u8RowIndex][Local_u8ColumnIndex];
				return Local_u8PressedKey;
			}

		}

		//Deactivate current column
		DIO_u8SetPinValue(KPD_PORT,Local_u8ColumnArr[Local_u8ColumnIndex],DIO_u8PIN_HIGH);

	}

	return Local_u8PressedKey;
}

