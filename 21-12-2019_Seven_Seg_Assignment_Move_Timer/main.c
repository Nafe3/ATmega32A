#include <util/delay.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "PORT_interface.h"
#include "SEVEN_SEGMENT-interface.h"
#include "DIO_interface.h"
void main(void)
{
	portInitialize();
	disableSevenSegment(0);
	disableSevenSegment(1);
	disableSevenSegment(2);
	disableSevenSegment(3);
	disableSevenSegment(4);
	disableSevenSegment(5);


	u32 millis=0;
	u32 rakam1=0;
	u32 rakam2=0;

	u8  seconds=0;
	u8  rakam3=0;
	u8  rakam4=0;

	u8  minutes=0;
	u8  rakam5=0;
	u8  rakam6=0;
	while(1)
	{
		if(millis>99)
		{
			seconds++;
			millis=0;
		}
		else
			millis++;
		if(seconds>59)
		{
			minutes++;
			seconds=0;
		}
		rakam1=millis%10;
		rakam2=millis/10;
		rakam3=seconds%10;
		rakam4=seconds/10;
		rakam5=minutes%10;
		rakam6=minutes/10;

		//switching between the two seven segments
		//0
		disableSevenSegment(1);
		disableSevenSegment(2);
		disableSevenSegment(3);
		disableSevenSegment(4);
		disableSevenSegment(5);
		setNumber(rakam1);
		enableSevenSegment(0);
		//_delay_ms(2);

		//1
		disableSevenSegment(0);
		disableSevenSegment(2);
		disableSevenSegment(3);
		disableSevenSegment(4);
		disableSevenSegment(5);
		setNumber(rakam2);
		enableSevenSegment(1);
		//_delay_us(2);

		//2
		disableSevenSegment(0);
		disableSevenSegment(1);
		disableSevenSegment(3);
		disableSevenSegment(4);
		disableSevenSegment(5);
		setNumber(rakam3);
		enableSevenSegment(2);
		//_delay_us(2);

		//3
		disableSevenSegment(0);
		disableSevenSegment(1);
		disableSevenSegment(2);
		disableSevenSegment(4);
		disableSevenSegment(5);
		setNumber(rakam4);
		enableSevenSegment(3);
		//_delay_us(2);

		//4
		disableSevenSegment(0);
		disableSevenSegment(1);
		disableSevenSegment(2);
		disableSevenSegment(3);
		disableSevenSegment(5);
		setNumber(rakam5);
		enableSevenSegment(4);
		//_delay_us(2);

		//5
		disableSevenSegment(0);
		disableSevenSegment(1);
		disableSevenSegment(2);
		disableSevenSegment(3);
		disableSevenSegment(4);
		setNumber(rakam6);
		enableSevenSegment(5);
		//_delay_us(2);

		//if(rakam1>9){rakam1=0;}
		//else if(rakam1<0){rakam1=9;}
		//if(rakam2>9){rakam2=0;}
		//else if(rakam2<0){rakam2=9;}
	}
}
