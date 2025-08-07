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

#include "ADC_INT.h"


void LED_TEMP(u32 temp)
{
	if (temp<=25)
	{
		DIO_setPinValue(DIO_PINC0,DIO_HIGH);
	}
	else if (temp > 25 && temp==30)
	{
		DIO_setPinValue(DIO_PINC0,DIO_HIGH);
		DIO_setPinValue(DIO_PINC1,DIO_HIGH);
	}
	else if (temp>30 && temp==35)
	{
		DIO_setPinValue(DIO_PINC0,DIO_HIGH);
		DIO_setPinValue(DIO_PINC1,DIO_HIGH);
		DIO_setPinValue(DIO_PINC2,DIO_HIGH);
	}
	
}


int main(void)
{
	DIO_setPinDir(DIO_PINC0,DIO_OUTPUT);
	DIO_setPinDir(DIO_PINC1,DIO_OUTPUT);
	DIO_setPinDir(DIO_PINC2,DIO_OUTPUT);
	LCD_init();
	ADC_init();
	u16 digital ;
	f32 analog ;
	u32 temp ;
	while (1)
	{
		digital = ADC_read(ADC_CH1);
		analog = ADC_convertAnalog(digital);
		temp = analog*100 ;
		LCD_clearDis();
		LCD_sendNum(temp);
		LCD_sendData('C');
		_delay_ms(1000);
		LED_TEMP(temp);
	}
}