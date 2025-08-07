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

#include "SS_INT.h"

int main(void)
{	
	/*SS_init();
	u8 num =0  ;
	u32 timer = 0;
	u8 state , state2 ;
	u8 flag =0 ;
	//button
	DIO_setPinDir(DIO_PINB0,DIO_INPUT);*/
	
	LCD_init();
	u8 x =0 ;
	
	/*LCD_sendStr("Hady");
	LCD_sendNum(123);
	LCD_sendFloatNum(123.456);*/
    while (1) 
    {
		LCD_GoTo(x,1);
		x++;
		LCD_sendData('a');
		LCD_sendData('b');
		_delay_ms(500);
		LCD_clearDis();
	
		
		
		/*timer++;
		if(timer==500 && flag == 0)
		{
			num++;
			timer=0;
		}
		SS_writeNum(num);
		
		if(num==0)
		{
			DIO_setPinValue(DIO_PINA3, DIO_HIGH);
		}
		//stop button
		state = DIO_readPinValue(DIO_PINB0);
		if(state == DIO_HIGH)
		{
			flag = 1;
			while(DIO_readPinValue(DIO_PINB0)==DIO_HIGH);
			
		}
		//reset button
		state2 = DIO_readPinValue(DIO_PIND6);
		if(state2 == DIO_HIGH)
		{
			num = 0;
			timer = 0;
			flag =0;
			while(DIO_readPinValue(DIO_PIND6)==DIO_HIGH);
			
		}
		
		
		for (i=0;i<=99;i++)
		{
			SS_writeNum(i);
			state = DIO_readPinValue(DIO_PINB0);
			if(state == DIO_HIGH)
			{
				while(DIO_readPinValue(DIO_PINB0)==DIO_HIGH);
				i=0;
			}
			
		}
		if(num==0)
		{
			DIO_setPinValue(DIO_PINA3,DIO_HIGH)
		}
		
		
		u8 state = DIO_readPinValue(DIO_PIND6);
		if(state == DIO_HIGH)
		{
				
			while(DIO_readPinValue(DIO_PIND6)==DIO_HIGH);
		}
		
		
		DIO_setPinValue(DIO_PINC2,DIO_HIGH);
		_delay_ms(1000);
		DIO_setPinValue(DIO_PINC2,DIO_LOW);
		_delay_ms(1000);*/
    }
}