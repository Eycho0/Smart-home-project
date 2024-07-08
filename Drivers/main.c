/*
 * main.c
 *
 *  Created on: Nov 5, 2023
 *      Author: olege
 */
#include "DIO drivers/dio.h"
#include "LED drivers/LED.h"
#include "PB drivers/PB.h"
#include "Sev_Seg drivers/sev_seg.h"
#include "CLCD drivers/CLCD.h"
#include "Keypad drivers/Keypad.h"
#include "Interrupt drivers/Interrupt.h"
#include "ADC2/MADC_interface.h"
#include "Timer drivers/Timer.h"
#include "UART drivers/UART.h"
#include "EEPROM drivers/EEPROM.h"
#include "Servo/servo.h"
#include <avr/eeprom.h>







void checkldr(void);


int main()
{

	GIE_vEnable();
	DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_OUTPUT);
	char arr[][13]={"1.Door","2.Lights","3.Fan","4.Music","5.Tempreature",""};
	CLCD_vInit();
	KPD_vKPDInit();
	Timer1_vInit();
	Timer0_vInit();
	Timer1_vSetICR(20000);
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN5,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN5,DIO_u8PIN_LOW);



	DIO_u8SetPinDirection(DIO_u8PORTD, DIO_u8PIN0, DIO_u8PIN_OUTPUT);
	MADC_voidInit(MADC_VREF_AVCC, MADC_PRESCALER_16, MADC_RESOLUTION_8BITS);
	u8 reading;

	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN3,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN3,DIO_u8PIN_LOW);

	DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_LOW);

	DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_LOW);

	Timer0_u8SetCallBack(&checkldr);


	CLCD_vSendString("Welcome To Smart      Home");
	_delay_ms(3000);

	u8 music=0;
	u8 door=0;
	u8 fan=0;
	u8 led=0;
	u8 error=0;
	u8 layer=0;
	u8 trials=3;
	u8 pressed_key;

	while(1)
	{

		if(layer==0)
		{
			CLCD_vClearScreen();
			CLCD_vSendString("Select User");
			_delay_ms(1500);

			CLCD_vClearScreen();
			CLCD_vSendString("1.user1");
			CLCD_vGoToXY(0,1);
			CLCD_vSendString("2.user2");

			layer=1;
		}
		do
		{

			u8 pressed_key = 0xff;
			pressed_key = KPD_u8GetPressedKey();
			if (pressed_key == 1 || layer>1)
			{
				while(layer>0)
				{
				if(eeprom_read_byte(100)==0xff)
				{
					CLCD_vClearScreen();
					CLCD_vGoToXY(0,0);
					CLCD_vSendString("New user!");

					_delay_ms(500);
					CLCD_vClearScreen();
					CLCD_vSendString("Enter password:");
					_delay_ms(500);

					u8 len=0;
					u8 pos=12;
					do
					{	u8 pass=0xff;
						while(pass==0xff)
						{
						pass= KPD_u8GetPressedKey();
						}
						eeprom_write_byte((u8*)102+len,pass);
						CLCD_vGoToXY(len,1);
						CLCD_vSendNumber(pass);
						_delay_ms(200);
						CLCD_vGoToXY(len,1);
						CLCD_vSendString("*");
						len++;
					}while(len<4);

					CLCD_vClearScreen();
					CLCD_vSendString("Password is set");
					eeprom_write_byte((u8*)100,0);
					_delay_ms(500);
					layer=0;
					break;
				}

				else
				{
					if(trials==0)
					{
						CLCD_vClearScreen();
						CLCD_vSendString("SYSTEM LOCKED");
						DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_HIGH);
						while(1);
					}
					if(layer<2)
					{
					CLCD_vClearScreen();
					CLCD_vSendString("Enter password:");
					u8 len=0;
					error=0;
					do
					{
						u8 pass = 0xff;
						while (pass == 0xff) {
							pass = KPD_u8GetPressedKey();
						}
						if(pass!=EEPROM_u8Read(102+len))
						{
							error=1;
						}
						CLCD_vGoToXY(len, 1);
						CLCD_vSendNumber(pass);
						_delay_ms(200);
						CLCD_vGoToXY(len, 1);
						CLCD_vSendString("*");
						len++;
					} while (len < 4);
					}

					if(error)
					{
						trials--;
						CLCD_vClearScreen();
						CLCD_vSendString("WRONG PASSWORD");
						_delay_ms(500);
						CLCD_vClearScreen();
						CLCD_vSendString("Remaining trials");
						CLCD_vGoToXY(0,1);
						CLCD_vSendNumber(trials);
						_delay_ms(700);
					}

					else
					{


						if(layer!=2)
						{
						CLCD_vClearScreen();
						CLCD_vSendString("Welcome User1");
						_delay_ms(1000);
						}
						CLCD_vClearScreen();
						CLCD_vSendString("Select function:");
						_delay_ms(1000);
						CLCD_vClearScreen();
						u8 cursor=0;
						u8 mode=0xff;
						u8 op;
						while(mode==0xff)
						{
						    CLCD_vGoToXY(0, 0);
						    CLCD_vSendString(arr[cursor]);
						    CLCD_vGoToXY(0, 1);
						    CLCD_vSendString(arr[cursor + 1]);
							op=KPD_u8GetPressedKey();
							if(op == '+')
							{
								CLCD_vClearScreen();
								if(cursor<4)
									cursor++;
								CLCD_vGoToXY(0,0);
								CLCD_vSendString(arr[cursor]);
								CLCD_vGoToXY(0,1);
								CLCD_vSendString(arr[cursor+1]);
							}

							else if(op=='-')
							{
		     					CLCD_vClearScreen();
		     					if (cursor > 0)
		     						cursor--;
		     					CLCD_vGoToXY(0, 0);
		     					CLCD_vSendString(arr[cursor]);
		     					CLCD_vGoToXY(0, 1);
		     					CLCD_vSendString(arr[cursor + 1]);

							}
							else
							{
									mode = op;
							}

						 }

						   switch(mode)
						   {
						   	case 1:
								CLCD_vClearScreen();
								if(door==0)
								{
									CLCD_vSendString("door opening");
									servo_rotate(180);
									door=1;
								}
								else if(door==1)
								{
									CLCD_vSendString("door closing");
									servo_rotate(0);
									door=0;
								}

								_delay_ms(2000);
								break;
						   	case 2:
								CLCD_vClearScreen();
								if(led==0)
								{
									CLCD_vSendString("Lights on");
									DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_HIGH);
									led=1;
								}
								else if(led==1)
								{
									CLCD_vSendString("Lights off");
									DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_LOW);
									led=0;
								}

								_delay_ms(2000);
								break;
						   	case 3:
								CLCD_vClearScreen();
								if(fan==0)
								{
									CLCD_vSendString("fan on");
									DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN1,DIO_u8PIN_OUTPUT);
									DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN2,DIO_u8PIN_OUTPUT);

									DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN1,DIO_u8PIN_HIGH);
									DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN2,DIO_u8PIN_HIGH);

									fan=1;
								}
								else if(fan==1)
								{
									CLCD_vSendString("fan off");
									DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN1,DIO_u8PIN_OUTPUT);
									DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN2,DIO_u8PIN_OUTPUT);

									DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN1,DIO_u8PIN_LOW);
									DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN2,DIO_u8PIN_LOW);
									fan=0;
								}
								_delay_ms(2000);
								break;
						   	case 4:
								if(music==0)
								{
									CLCD_vSendString("Music on");
									DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN3,DIO_u8PIN_HIGH);
									music=1;
								}
								else if(music==1)
								{
									CLCD_vSendString("Music off");
									DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN3,DIO_u8PIN_LOW);
									music=0;
								}
								_delay_ms(1000);
								DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN3,DIO_u8PIN_LOW);

								break;
						   	case 5:
								CLCD_vClearScreen();
								CLCD_vSendString("Temperature : ");
								u8 u8Home_Temperature =  MADC_u8ReadADC(2);
								CLCD_vSendNumber(2*u8Home_Temperature);
								_delay_ms(2000);
								break;
						   }



						CLCD_vClearScreen();
						CLCD_vGoToXY(0, 0);
						CLCD_vSendString("1. User select");
						CLCD_vGoToXY(0, 1);
						CLCD_vSendString("2. Mode select");

						u8 ret = 0xff;
						while (ret = 0xff)
						{
							ret = KPD_u8GetPressedKey();
							if (ret == 1) {
								layer = 0;
								break;
							}
							else if (ret == 2)
							{
								layer = 2;
								break;
							}
						}


					}
				}
			}
			}

		} while (pressed_key = 0xff && layer==1);
	}
}


void checkldr(void)
{
	static u16 cnt=0;
	cnt++;
	u8 reading;
	if (cnt >= 50)
	{
		reading = MADC_u8ReadADC(MADC_CHANNEL_ADC3);
		if (reading < 5) {
			LED_u8On(DIO_u8PORTD, DIO_u8PIN0);
		} else {
			LED_u8Off(DIO_u8PORTD, DIO_u8PIN0);
		}
		cnt = 0;
	}
}

