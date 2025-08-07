
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
#include "SPI_INT.h"
#include "I2C_INT.h"
#include"EEPROM_INT.h"
#include "ADC_INT.h"

volatile s16 capt1,capt2;
volatile u8 mask=0;
volatile u32 ov;
volatile u32 ovf;
int main(void)
{
	s16 count;
	f32 distance;
	u8 string[10];
	LCD_init();
	//LCD_String_xy(0,0,"Ultrasonic Sens");
	LCD_GoTo(0,0);
	LCD_sendStr("Ultrasonic Sens");
	DDRB |= (1<<DDB1);
	DDRB &= ~(1<<DDB0);
	cli();
	TCCR1A=0;
	TCCR1B=0;
	TCNT1=0;
	TCCR1B |= (1<<ICES1) | (1<<CS10);//Rising Edge, Prescaler=1
	TIMSK |= (1<<TICIE1) | (1<<TOIE1);
	GI_enable();
	
	while (1)
	{
		PORTB |= (1<<DIO_PINB1);
		_delay_ms(10);
		PORTB &= ~(1<<DIO_PINB1);
		if(mask==2)
		{
			mask=0;
			count = ((u32)capt2+(u32)(ovf*65536))-(u32)capt1;
			distance = (f32)count/932.95;
			dtostrf(distance,2,2,string);
			strcat(string,"cm  ");
			//LCD_String_xy(1,0,"Dist= ");
			LCD_GoTo(1,0);
			LCD_sendStr("Dist= ");
			//LCD_String_xy(1,7,string);
			LCD_GoTo(1,7);
			LCD_sendStr(string);
			_delay_ms(350);
			ovf=0;ov=0;
			TCCR1B |= (1<<ICES1);
			TIFR=(1<<ICF1) | (1<<TOIE1);
			TIMSK |= (1<<TICIE1) | (1<<TOIE1);
		}
	}
}

ISR(TIMER1_OVF_vect)
{
	ov++;
}

ISR(TIMER1_CAPT_vect)
{
	if(mask==0)
	{
		capt1=ICR1;
		TCCR1B &= ~(1<<ICES1);//Falling Edge
		ov=0;
	}
	
	else if(mask==1)
	{
		capt2=ICR1;
		ovf=ov;
		TIMSK &= ~ ((1<<TICIE1)|(1<<TOIE1));//Disable Input Capture Interrupt, TOV
	}
	mask++;
}