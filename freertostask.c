
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


void task1(void * pvParameters)
{
	while (1)
	{
		DIO_togglePinValue(DIO_PINC2);
		vTaskDelay(500);
	}
	
	
}

void task2(void * pvParameters )
{
	static u8 counter = 0 ;
	while (1)
	{
		DIO_togglePinValue(DIO_PINC7);
		
		counter++;
		if (counter==12)
		{
			vTaskResume(xHandle1);
		}
		
		vTaskDelay(200);
	}
	
	    
}

void task3(void * pvParameters)
{
	while (1)
	{
		u8 state = DIO_readPinValue(DIO_PINA3);
		if(state == DIO_HIGH)
		{
			vTaskSuspend(xHandle1);
		}
		
	
	//vTaskDelay(400);
	}
}

int main(void)
{
	
	DIO_setPinDir(DIO_PINA3,DIO_OUTPUT);
	DIO_setPinDir(DIO_PINC2,DIO_OUTPUT);
	DIO_setPinDir(DIO_PINC7,DIO_OUTPUT);
	
	xTaskCreate(
	task1,       /* Function that implements the task. */
	NULL,          /* Text name for the task. */
	100,      /* Stack size in words, not bytes. */
	NULL,    /* Parameter passed into the task. */
	1,/* Priority at which the task is created. */
	&xHandle1 );      /* Used to pass out the created task's handle. */

    xTaskCreate(task2,NULL,100,NULL,1,NULL);
	
	//xTaskCreate(task3,NULL,100,NULL,1,NULL);
	
	
	
	
	vTaskStartScheduler();
	
	
	while (1)
	{
		
	}
}