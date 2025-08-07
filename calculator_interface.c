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

#include "GI_INT.h"
#include "EXT_INT.h"


int main(void)
{
	KPD_init();
	LCD_init();
	u8 calc[3] = {'1','+','3'} ;
	u8 arr[3],i = 0, ans ;
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
		
		if (i==3)
		{
			if (arr[1] == '+')
			{
				LCD_clearDis();
				ans = (arr[0] - 48) + (arr[2] - 48);
				LCD_sendNum(ans);
				i = 5 ;
			}
			else if (arr[1]=='-')
			{
				LCD_clearDis();
				ans = (arr[0] - 48) - (arr[2] - 48);
				LCD_sendNum(ans);
				i = 5 ;
			}
			else if (arr[1]=='*')
			{
				LCD_clearDis();
				ans = (arr[0] - 48) * (arr[2] - 48);
				LCD_sendNum(ans);
				i = 5 ;
			}
			else if (arr[1]=='/')
			{
				LCD_clearDis();
				ans = (arr[0] - 48) / (arr[2] - 48);
				LCD_sendNum(ans);
				i = 5 ;
			}
		
		}
		if (key == KPD_ROW3_COL0)
		{
			i = 0;
			LCD_clearDis();
		}
	}
}
