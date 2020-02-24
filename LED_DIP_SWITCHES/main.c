#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "PORT_interface.h"
#include "LED_INTERFACE.h"

void main (void)
{
	portInitialize();

	while(1)
	{
	if (getPinValue('D',0)==0)
		{
			setPinValue('D',4,1);
		}
	else
		{
		setPinValue('D',4,0);
		}

	if (getPinValue('D',1)==0)
		{
			setPinValue('D',5,1);
		}
	else
		{
			setPinValue('D',5,0);
		}

	if (getPinValue('D',2)==0)
	{
		setPinValue('D',6,1);
	}
	else
	{
		setPinValue('D',6,0);
	}

	if (getPinValue('D',3)==0)
		{
			setPinValue('D',7,1);
		}
	else
		{
			setPinValue('D',7,0);
		}
	}
}
