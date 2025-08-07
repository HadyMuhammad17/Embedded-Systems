
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

u8 offFlag = 0;
u32 ovCounter=0;

void callback()
{
	ovCounter++;
	if(ovCounter == 39063)
	{
		offFlag = 1;
	}
	DIO_togglePinValue(DIO_PIND6);
}

//F_cpu = 16 MHZ
//prescalar = 8
//Td = 5sec,//numOv = 4882
//Td = 2h -> 2*60*60sec,//numOv = 7031250


int main(void)
{
	SS_init();
	ADC_init();
	EEPROM_init();
	GI_enable();
	//TIMER0_initFastPWM();
	
	DIO_setPinDir(DIO_PIND6,DIO_OUTPUT);
	DIO_setPinDir(DIO_PINA2,DIO_OUTPUT);
	DIO_setPinDir(DIO_PINB4,DIO_OUTPUT);
	DIO_setPinDir(DIO_PINB5,DIO_OUTPUT);
	DIO_setPinDir(DIO_PINB3,DIO_OUTPUT);
	
	DIO_setPinDir(DIO_PIND3,DIO_OUTPUT);
	DIO_setPinDir(DIO_PIND2,DIO_OUTPUT);
	
	u8 Td = EEPROM_readData(100);
	
	TIMER0_initNormal();
	TIMER0_setCallbackOv(callback);
	TIMER0_start(TIMER0_DIV8);

	while (1)
	{
		if(offFlag == 0)
		{
			SS_writeNum(Td);
			
			u8 Tc = ADC_read(ADC_CH1);
			
			Tc = ADC_convertAnalog(Tc) * 100;
			
			if (Tc > Td)
			{
				DIO_setPinValue(DIO_PINA2,DIO_LOW);
				
				//TIMER0_start(TIMER0_DIV64);
				//TIMER0_setOcr((Tc*255)/(Tc+Td));
				DIO_setPinValue(DIO_PINB3,DIO_HIGH);
				
				DIO_setPinValue(DIO_PINB4,DIO_HIGH);
				DIO_setPinValue(DIO_PINB5,DIO_LOW);
			}
			else if (Tc < Td)
			{
				DIO_setPinValue(DIO_PINB4,DIO_LOW);
				DIO_setPinValue(DIO_PINB5,DIO_LOW);
				
				DIO_setPinValue(DIO_PINB3,DIO_LOW);
				//TIMER0_start(TIMER0_STOP);
				
				DIO_setPinValue(DIO_PINA2,DIO_HIGH);
			}
			
			if (DIO_readPinValue(DIO_PIND2) == DIO_HIGH)
			{
				while(DIO_readPinValue(DIO_PIND2) == DIO_HIGH);
				Td ++;
				EEPROM_writeData(Td,100);
				ovCounter=0;
			}
			else if (DIO_readPinValue(DIO_PIND3) == DIO_HIGH)
			{
				while(DIO_readPinValue(DIO_PIND3) == DIO_HIGH);
				Td --;
				EEPROM_writeData(Td,100);
				ovCounter=0;
			}
		}
		else if(offFlag == 1)
		{
			DIO_setPinValue(DIO_PINB4,DIO_LOW);
			DIO_setPinValue(DIO_PINB5,DIO_LOW);
			DIO_setPinValue(DIO_PINB3,DIO_LOW);
			DIO_setPinValue(DIO_PINA2,DIO_LOW);
			
		}
	}
}