#include <util/delay.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
void main(void)
{
	portInitialize();
	while(1)
	{

	if(getPinValue('D',0)==0)
		{
			setPinValue('C',1,1);

		}
	else
		{
			setPinValue('C',1,0);
		}

	}
}
