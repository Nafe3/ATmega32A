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
	enableSevenSegment(1);
	enableSevenSegment(2);
	enableSevenSegment(3);
	enableSevenSegment(4);
	enableSevenSegment(5);
	
	//disableSevenSegment(0);
	disableSevenSegment(1);
	disableSevenSegment(2);
	disableSevenSegment(3);
	disableSevenSegment(4);
	disableSevenSegment(5);
	s8 LedToOperate=0;
	s8 SvnSegToOperate=0;
	while(1)
	{
	setLed(LedToOperate);
	setSvnSeg(SvnSegToOperate);
	if(getPinValue('B',6)==0)//move clockwise
		{
			_delay_ms(200);
			if(LedToOperate==3)
			{
				if(SvnSegToOperate==5)
					LedToOperate++;
				else
					SvnSegToOperate++;
			}
			else if(LedToOperate==0)
			{
				if(SvnSegToOperate==0)
					LedToOperate++;
				else
					SvnSegToOperate--;
			}
			else
			{
				LedToOperate++;
			}
		}

	if(getPinValue('B',7)==0)//move anti-clockwise
		{
			_delay_ms(200);
			if(LedToOperate==3)
			{
				if(SvnSegToOperate==0)
					LedToOperate--;
				else
					SvnSegToOperate--;
			}
			else if(LedToOperate==0)
			{
				if(SvnSegToOperate==5)
					LedToOperate--;
				else
					SvnSegToOperate++;
			}
			else
			{
				LedToOperate--;
			}
		}
	
	if(LedToOperate>5)
		{
			LedToOperate=0;
		}
	if(LedToOperate<0)
		{
			LedToOperate=5;
		}
	if(SvnSegToOperate>5)
		{
			SvnSegToOperate=0;
		}
	if(SvnSegToOperate<0)
		{
			SvnSegToOperate=5;
		}
	
	}
}
