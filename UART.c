/*
 * Nasr75Proj.c
 *
 * Created: 03/04/2024 08:50:20 PM
 * Author : AMIT
 */ 

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#define F_CPU 16000000UL
#include <util/delay.h>

#include "DIO_INT.h"
#include "SS_INT.h"

#include "LCD_INT.h"

#include "KPD_INT.h"

#include "EXT_INT.h"
#include "GI_INT.h"
#include "TIMER0_INT.h"
#include "TIMER1_INT.h"
#include "WDT_INT.h"
#include "TIMER1_INT.h"
#include "UART_INT.h"

int main(void)
{
	UART_init();
	
	u8 enteredPass[4];
	u8 pass[4]={"1234"};
	u8 i =0;
	u8 blockCounter = 0;
	while (1)
	{
		u8 key = UART_receiveData();
		if(key != KPD_UNPRESSED)
		{
			while(UART_receiveData() != KPD_UNPRESSED);
			LCD_sendData(key);
			enteredPass[i] = key;
			i++;
		}
		if(i==4)
		{
			u8 flag = 0;
			for(u8 k=0; k<4; k++)
			{
				if(enteredPass[k] == pass[k])
				{
					flag = 1;
				}
				else
				{
					flag = 0;
					break;
				}
			}
			if(flag == 1)
			{
				UART_sendStr("welcom");
				i=5;
			}
			else
			{
				blockCounter++;
				if(blockCounter == 3)
				{
					UART_sendStr("block");
					while(1);
				}
				UART_sendStr("try again");
				
				_delay_ms(1000);
				UART_sendData(key);
				i = 0;
			}
		}
	}
	
	
	/*UART_init();
	DIO_setPinDir(DIO_PINC2,DIO_OUTPUT);
	while (1)
	{
		//UART_sendData('e');
		//_delay_ms(1000);
		
		u8 receivedData = UART_receiveData();
		if(receivedData == 'n')
		{
			DIO_setPinValue(DIO_PINC2,DIO_HIGH);
		}
		else if(receivedData == 'f')
		{
			DIO_setPinValue(DIO_PINC2,DIO_LOW);
		}
	}*/
}

