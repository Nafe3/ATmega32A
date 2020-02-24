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

	s8 rakam1=0;
	s8 rakam2=0;
	u8 speedup1=0;
	u8 speedup2=0;
	u8 speedup12=0;
	u8 delay=200;
	while(1)
	{

		//switching between the two seven segments
			disableSevenSegment(1);
			setNumber(rakam1);
			enableSevenSegment(0);
			_delay_ms(5);

			disableSevenSegment(0);
			setNumber(rakam2);
			enableSevenSegment(1);
			_delay_us(800);

		if(getPinValue('B',6)==0 && getPinValue('B',7)==0)
		{
				speedup12++;
				speedup1=0;
				speedup2=0;
				if(speedup12>10)
					_delay_ms(delay/2);
				else
					_delay_ms(delay);
				rakam2--;
				rakam1--;
		}
		else if(getPinValue('B',6)==0)
		{
			speedup1++;
			speedup2=0;
			speedup12=0;

			if(speedup1>10)
				_delay_ms(delay/2);
			else
				_delay_ms(delay);
			rakam1++;
		}
		else if(getPinValue('B',7)==0)
		{
			speedup2++;
			speedup1=0;
			speedup12=0;

			if(speedup2>10)
				_delay_ms(delay/2);
			else
				_delay_ms(delay);
			rakam2++;
		}
		
		if(rakam1>9){rakam1=0;}
		else if(rakam1<0){rakam1=9;}
		if(rakam2>9){rakam2=0;}
		else if(rakam2<0){rakam2=9;}
	}
}

