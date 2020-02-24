#include <util/delay.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "PORT_interface.h"
#include "SEVEN_SEGMENT-interface.h"
#include "DIO_interface.h"
void main(void)
{
	portInitialize();
	enableSevenSegment(0);
	//enableSevenSegment(1);
	enableSevenSegment(2);
	enableSevenSegment(3);
	enableSevenSegment(4);
	enableSevenSegment(5);

	s8 rakam=0;
	while(1)
	{
	/*
	setNumber(0);
	_delay_ms(500);
	setNumber(1);
	_delay_ms(500);
	setNumber(2);
	_delay_ms(500);
	setNumber(3);
	_delay_ms(500);
	setNumber(4);
	_delay_ms(500);
	setNumber(5);
	_delay_ms(500);
	setNumber(6);
	_delay_ms(500);
	setNumber(7);
	_delay_ms(500);
	setNumber(8);
	_delay_ms(500);
	setNumber(9);
	_delay_ms(500);
	*/
	setNumber(rakam);
	if(getPinValue('B',6)==0)
		{
		_delay_ms(200);
		rakam++;
		}

	if(getPinValue('B',7)==0)
		{
		_delay_ms(200);
		rakam--;
		}
	if(rakam>9){rakam=0;}
	if(rakam<0){rakam=9;}
	}
}
