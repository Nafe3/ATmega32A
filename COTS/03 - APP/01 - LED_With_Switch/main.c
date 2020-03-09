#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_register.h"
#include "DIO_config.h"

void main (void)
{
	u8 switchState;
	
	/*Set A0 direction to input*/
	setPinDir('A',0,0);
	
	/*Set A1 direction to input*/
	setPinDir('A',1,1);
	
	switchState = getPinValue('A',0);
	
	while(1)
	{
	if (switchState==0)
	{
		/*Set LED on*/
		setPinVal('A',1,1);
	}
	else
	{
		/*Set LED off*/
		setPinVal('A',1,0);
	}
	}
}