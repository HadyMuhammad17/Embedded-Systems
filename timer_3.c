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


//f32 Ttick = (64.0/16000000)*1000;
f32 Ttick = 0.004; //ms

u32 dis = 0;

void ultrasonicFunc()
{
	static u8 edge = 0;
	//rising
	if(edge == 0)
	{
		TIMER1_setPreload(0);
		TIMER1_initIcu(TIMER1_ICU_FALING);
		edge=1;
	}
	//falling
	else if(edge == 1)
	{
		u16 numTicks = TIMER1_getIcr();
		f32 time = numTicks * Ttick;
		dis = 17*time;
		TIMER1_initIcu(TIMER1_ICU_RISING);
		edge=0;
	}
}

int main(void)
{	
	GI_enable();
	TIMER1_initIcu(TIMER1_ICU_RISING);
	TIMER1_setCallbackIcu(ultrasonicFunc);
	
	//trigger
	DIO_setPinDir(DIO_PIND1,DIO_OUTPUT);
	//echo
	DIO_setPinDir(DIO_PIND6,DIO_INPUT);
	
	LCD_init();
    
	while (1) 
    {
		//trigger
		DIO_setPinValue(DIO_PIND1,DIO_HIGH);
		_delay_us(10);
		DIO_setPinValue(DIO_PIND1,DIO_LOW);
		
		LCD_clearDis();
		LCD_sendStr("d = ");
		LCD_sendNum(dis);
		LCD_sendStr(" cm");
		_delay_ms(1000);
		
		
		
    }
}
