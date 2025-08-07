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
	DIO_setPinDir(DIO_PINC5, DIO_OUTPUT);
	DIO_setPinDir(DIO_PINC6, DIO_OUTPUT);
	DIO_setPinDir(DIO_PIND5, DIO_OUTPUT);
	DIO_setPinDir(DIO_PIND6, DIO_OUTPUT);
	DIO_setPinDir(DIO_PIND2, DIO_OUTPUT);
	
	u8 state ;
	u8 state1 ; 
	
	//oc pin output
	DIO_setPinDir(DIO_PINB3, DIO_OUTPUT);
	
	//init PWM
	TIMER0_initFastPwm();
	
	//Duty cycle
	TIMER0_setOcr(127);
	
	//Frequency
	TIMER0_start(TIMER0_DIV8);
	
	while (1)
	{
		 state = DIO_readPinValue(DIO_PIND6);
		
		if (state==DIO_HIGH)
		{
			DIO_setPinValue(DIO_PINC5,DIO_HIGH);
			DIO_setPinValue(DIO_PINC6,DIO_LOW);
			DIO_setPinValue(DIO_PIND5,DIO_HIGH);
		}
		 state1 = DIO_readPinValue(DIO_PIND2);
		 
		 if (state1==DIO_HIGH)
		 {
			 DIO_setPinValue(DIO_PINC5,DIO_LOW);
			 DIO_setPinValue(DIO_PINC6,DIO_HIGH);
			 DIO_setPinValue(DIO_PIND5,DIO_HIGH);
		 }
	}
}
