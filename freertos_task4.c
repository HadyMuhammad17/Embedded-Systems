
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
#include "semphr.h"
#include "event_groups.h"

TaskHandle_t xHandle1;
TaskHandle_t xHandle2;
TaskHandle_t xHandle3;
TaskHandle_t xHandle4;

u8 state  ;
SemaphoreHandle_t A ;

void task1(void * pvParameters)
{
	
	
	while(1)
	{
		u8 state =DIO_readPinValue(DIO_PIND2);
		if(state==DIO_HIGH)
		{
			xSemaphoreGive(A);
			//while(DIO_readPinValue(PIND2)==DIO_HIGH);
		}
			
		vTaskDelay(250);
	
		
	}
	
}

void task2(void * pvParameters)
{
	
	while (1)
	{
		if (uxSemaphoreGetCount(A)==3)
		{
			DIO_setPinValue(DIO_PINC2,DIO_HIGH);
			//DIO_togglePinValue(PINC2);
			//xSemaphoreTake(A);
		}
		vTaskDelay(250);
		
	
	}
	
	
}



int main(void)
{
	
	DIO_setPinDir(DIO_PIND2,DIO_INPUT);
	DIO_setPinDir(DIO_PIND2,DIO_OUTPUT);
	
	
	A = xSemaphoreCreateCounting(3,0);
	
	
	
	xTaskCreate(task1,NULL,100,NULL,3,&xHandle1);
	
	 xTaskCreate(task2,NULL,100,NULL,3,&xHandle2);
	 
	vTaskStartScheduler();
	
	

	
	while (1)
	{
		
	}
}


