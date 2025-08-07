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


#include "TIMER0_INT.h"
#include "TIMER1_INT.h"


int main(void)
{	
	
	//DIO_setPinDir(DIO_PINC5, DIO_OUTPUT);
	//DIO_setPinDir(DIO_PINC6, DIO_OUTPUT);
	
	//PWM pin
	DIO_setPinDir(DIO_PIND5, DIO_OUTPUT);
	
	TIMER1_initFastPwmMod14();
	TIMER1_setFrequency(50);
	
    while (1) 
    {
		TIMER1_setOcr(499);
		_delay_ms(1000);
		TIMER1_setOcr(249);
		_delay_ms(1000);
		
		/*u8 state = DIO_readPinValue(DIO_PIND6);
		if(state == DIO_HIGH)
		{
			DIO_setPinValue(DIO_PINC5,DIO_HIGH);
			DIO_setPinValue(DIO_PINC6,DIO_LOW);
			
			DIO_setPinValue(DIO_PIND5,DIO_HIGH);
			
		}
		
		u8 state2 = DIO_readPinValue(DIO_PIND2);
		if(state2 == DIO_HIGH)
		{
			DIO_setPinValue(DIO_PINC5,DIO_LOW);
			DIO_setPinValue(DIO_PINC6,DIO_HIGH);
			
			DIO_setPinValue(DIO_PIND5,DIO_HIGH);
		}*/
    }
}
