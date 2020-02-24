#include <util/delay.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
//#define DDRC  *((u8*)0x34)
//#define PORTC *((u8*)0x35)
void main(void)
{
	portInitialize();
	setPinDir('C',8,1);
	//DDRC=0b10000000;

	while(1)
	{
			//PORTC=0b10000000;
			//_delay_ms(1000);
			setPinValue('C',8,1);
			//_delay_ms(1000);
			//setPinValue('C',8,1);
			//_delay_ms(1000);
			//setPinValue('C',8,1);
			//_delay_ms(1000);
	}
}
