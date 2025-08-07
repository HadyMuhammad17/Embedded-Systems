
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


#define BIT_0	( 1 << 0 )
#define BIT_4	( 1 << 4 )

TaskHandle_t xHandle1;
TaskHandle_t xHandle2;
TaskHandle_t xHandle3;
TaskHandle_t xHandle4;

EventBits_t uxBits;

QueueHandle_t xQueue1, xQueue2;

EventGroupHandle_t EventGroup;



void task1(void * pvParameters)
{
	
	
	while(1)
	{
		u8 state =DIO_readPinValue(DIO_PIND2);
		if(state==DIO_HIGH  )
		{
			
			uxBits = xEventGroupSetBits(EventGroup, BIT_0  );
			
			while (DIO_readPinValue(DIO_PIND2) == DIO_HIGH );
			
			
		}
			
		vTaskDelay(250);
	
		
	}
	
}

void task2(void * pvParameters)
{
	
	while (1)
	{
		 uxBits = xEventGroupWaitBits(
	     EventGroup,   /* The event group being tested. */
		 BIT_0, /* The bits within the event group to wait for. */
		 pdTRUE,        /* BIT_0 & BIT_4 should be cleared before returning. */
		 pdFALSE,       /* Don't wait for both bits, either bit will do. */
		 0 );/* Wait a maximum of 100ms for either bit to be set. */

		if( ( uxBits & BIT_0 ) != 0 )
		{
			DIO_setPinValue(DIO_PINC2,DIO_HIGH);
		}
		vTaskDelay(250);
		
	
	}
	
	
}



int main(void)
{
	
	DIO_setPinDir(DIO_PIND2,DIO_INPUT);
	DIO_setPinDir(DIO_PINC2,DIO_OUTPUT);
	
	
	xTaskCreate(task1,NULL,100,NULL,3,&xHandle1);
	
	xTaskCreate(task2,NULL,100,NULL,3,&xHandle2);
	 
	EventGroup = xEventGroupCreate();
	
	/* Create a queue capable of containing 10 unsigned long values. */
	xQueue1 = xQueueCreate( 10, sizeof( unsigned long ) );

	 
	vTaskStartScheduler();
	
	

	
	while (1)
	{
		
	}
}




