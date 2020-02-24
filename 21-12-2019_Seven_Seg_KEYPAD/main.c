#include <util/delay.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "PORT_interface.h"
#include "SEVEN_SEGMENT-interface.h"
#include "DIO_interface.h"
#include "KEYPAD_interface.h"
#include "KEYPAD_config.h"
void main(void)
{
	portInitialize();
	enableSevenSegment(0);
	enableSevenSegment(1);
	enableSevenSegment(2);
	enableSevenSegment(3);
	enableSevenSegment(4);
	enableSevenSegment(5);

	disableSevenSegment(2);
	disableSevenSegment(3);
	disableSevenSegment(4);
	disableSevenSegment(5);

	u8 key=0;
	u8 units=0;
	u8 tens=0;
	while(1)
	{

		key=KEYPAD_GetPressedKey();
		

		if(key!=KEYPAD_NOKEYPRESS)
		{
			units=key%10;
			tens= key/10;
		}

		disableSevenSegment(1);
		setNumber(units);
		enableSevenSegment(0);

		_delay_ms(5);

		disableSevenSegment(0);
		setNumber(tens);
		enableSevenSegment(1);
		_delay_ms(5);


	}
}
