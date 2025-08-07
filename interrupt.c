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

u8 x = 0;
void shiftRight()
{
	x++;
}

void shiftLeft()
{
	x--;
}

int main(void)
{
	LCD_init();
	
	GI_enable();
	EXT_int0Init(EXT_RISING);
	//EXT_int1Init(EXT_RISING);

	EXT_setCallbackInt0(shiftRight);
	//EXT_setCallbackInt0(shiftLeft);
	
	while (1)
	{
		LCD_clearDis();
		LCD_GoTo(x ,0);
		LCD_sendStr("Joseph");
		_delay_ms(100);
	}
}