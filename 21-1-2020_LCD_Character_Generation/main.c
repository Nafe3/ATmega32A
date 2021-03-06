#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include<util/delay.h>
#include<stdio.h>

#include"DIO_interface.h"

#include "LCD_config.h"
#include "LCD_interface.h"

//LCD Commands
#define clear				0b00000001 //clear
#define home				0b00000010 //return to home
#define entry_mode_set		0b00000100 //mask the two least significant bits
#define display				0b

//LCD Display
#define screenUpperRigtLimit 0x0F
#define screenLowerRigtLimit 0x4F
#define screenUpperLeftLimit 0x00
#define screenLowerLeftLimit 0x40

#define default_Password	 1234

int main (void)
{
	portInitialize();
	CLCD_voidInitialize();

	//1 standing arms down
	  B01110,
	  B01110,
	  B01110,
	  B00100,
	  B01110,
	  B10101,
	  B01010,
	  B10001
//2 standing arms up
	  B01110,
	   B01110,
	   B01110,
	   B10101,
	   B01110,
	   B00100,
	   B00100,
	   B00100
	   //3 ball
	   B00000,
	     B00000,
	     B00000,
	     B01110,
	     B01110,
	     B01110,
	     B00000,
	     B00000
		 //4 ball pos 1
		 B01110,
		   B01110,
		   B01110,
		   B00100,
		   B01110,
		   B00100,
		   B01011,
		   B10001
		 //5 ball pos 2
     	   B01110,
		   B01110,
		   B01110,
		   B00100,
		   B01111,
	   	   B00100,
		   B01010,
		   B10001
			//6 ball pos 3
				 B01110,
				   B01110,
				   B01111,
				   B00100,
				   B01110,
				   B00100,
				   B01010,
				   B10001
	while(1)
	{




	}

return 0;
}
