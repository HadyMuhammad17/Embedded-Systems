/*
 * GccApplication1.c
 *
 * Created: 4/3/2024 10:58:15 PM
 * Author : DELL
 */ 

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "LCD_INT.h"

#define F_CPU 16000000UL
#include <util/delay.h>

#include "DIO_INT.h"
#include "KPD_INT.h"
#include "SS_INT.h"

int main(void)
{
	KPD_init();
	LCD_init();
	u8 password[4] = {'1','2','3','4'} ;
	u8 arr[4],i = 0 ;
	while (1)
	{
		u8 key = KPD_read();
		if(key != KPD_UNPRESSED)
		{
			while(KPD_read() != KPD_UNPRESSED);
			arr[i] =key ;
			i++ ;
			
			LCD_sendData(key);
		}
		if (i==4)
		{
			if (arr[0]==password[0]&&arr[1]==password[1]&&arr[2]==password[2]&&arr[3]==password[3])
			{
				LCD_clearDis();
				LCD_sendStr("welcome");
				break;
			}
		else
		{
			LCD_clearDis();
			LCD_sendStr("Invalid");
			_delay_ms(500);
			LCD_clearDis();
			i = 0 ;
			
		}
		}
	}
}
