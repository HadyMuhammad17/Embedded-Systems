
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
#include "RTOS_INT.h"

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"

TaskHandle_t xHandle1;
TaskHandle_t xHandle2;
TaskHandle_t xHandle3;
TaskHandle_t xHandle4;

s8 LEDNUM = 0 ;
u8 state,state1;

void task1(void * pvParameters)
{
	
	while(1)
	{
		DIO_setPinDir(DIO_PIND2,DIO_INPUT);
		DIO_setPinDir(DIO_PIND3,DIO_INPUT);
		DIO_setPinDir(DIO_PINC2,DIO_OUTPUT);
		DIO_setPinDir(DIO_PINC7,DIO_OUTPUT);
		DIO_setPinDir(DIO_PIND5,DIO_OUTPUT);
		
		vTaskDelay(100);
		
		vTaskSuspend(NULL);
	}
	
}

void task2(void * pvParameters)
{
	//vTaskSuspend(xHandle1);
	while (1)
	{
		
		state = DIO_readPinValue(DIO_PIND2);
		if(state == DIO_HIGH)
		{
			LEDNUM++;
			if(LEDNUM==3)
			{
				LEDNUM = 0 ;
			}
			
			while(DIO_readPinValue(DIO_PIND2)==DIO_HIGH);
			
		}
		
		
		
		vTaskDelay(250);
	}
	
	
}

void task3(void * pvParameters )
{
	while (1)
	{
		
		state1 = DIO_readPinValue(DIO_PIND3);
		if(state1 == DIO_HIGH )
		{
			LEDNUM--;
			if (LEDNUM==-1)
			{
				LEDNUM=2;
			}
			while(DIO_readPinValue(DIO_PIND3)==DIO_HIGH);
			
		}
		
		
		
		vTaskDelay(250);
	}
}

void task4(void * pvParameters)
{
	
	
	while (1)
	{
		if (LEDNUM==0)
		{
			DIO_setPinValue(DIO_PINC2,DIO_HIGH);
			DIO_setPinValue(DIO_PINC7,DIO_LOW);
			DIO_setPinValue(DIO_PIND5,DIO_LOW);
		}
		else if (LEDNUM==1)
		{
			DIO_setPinValue(DIO_PINC2,DIO_LOW);
			DIO_setPinValue(DIO_PINC7,DIO_HIGH);
			DIO_setPinValue(DIO_PIND5,DIO_LOW);
		}
		else if (LEDNUM==2)
		{
			DIO_setPinValue(DIO_PINC2,DIO_LOW);
			DIO_setPinValue(DIO_PINC7,DIO_LOW);
			DIO_setPinValue(DIO_PIND5,DIO_HIGH);
		}
		
		vTaskDelay(250);
		
	}
}

int main(void)
{
	
	
	
	xTaskCreate(task1,NULL,100,NULL,3,&xHandle1);
	
	
	xTaskCreate(
	task2,       /* Function that implements the task. */
	NULL,          /* Text name for the task. */
	100,      /* Stack size in words, not bytes. */
	NULL,    /* Parameter passed into the task. */
	2,/* Priority at which the task is created. */
	&xHandle2 );      /* Used to pass out the created task's handle. */

    xTaskCreate(task3,NULL,100,NULL,2,&xHandle3);
	
	xTaskCreate(task4,NULL,100,NULL,0,&xHandle4);
	
	vTaskStartScheduler();
	
	while (1)
	{
		
	}
}