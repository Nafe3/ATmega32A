#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include<util/delay.h>
#include<stdio.h>
#include"DIO_interface.h"

#include"PORT_interface.h"

#include "LCD_private.h"
#include "LCD_config.h"
#include "LCD_interface.h"
#include "KEYPAD_interface.h"
int main (void)
{
	portInitialize();
	CLCD_voidInitialize();

	/*CLCD_voidWriteData('*');
	CLCD_voidWriteData(78);
	CLCD_voidWriteData(79);
	CLCD_voidWriteData(80);
	CLCD_voidWriteData(81);
	CLCD_voidWriteData(82);
	CLCD_voidWriteData('*');*/

	u8 ch=0b00110001;
	u8 position=0;
	u8 key=0;
	while(1)
	{
		if(position==5)
		{
			//position=64;
			//CLCD_voidWriteCmd(0b00000010);//return home
			CLCD_voidWriteCmd(0b11000000);//second line
			position=0;
		}
		if(position==80)
			position=0;
		key=KEYPAD_GetPressedKey();
		if(key==1)
		{
			CLCD_voidWriteData(ch);
			ch++;
			position++;

			//printf("!!!Hello World!!!");
		    //fflush(stdout);
		}
		if(key==2)
		{
			CLCD_voidWriteCmd(0b00011100);//shifts all display to right

		}

		//if(KEYPAD_GetPressedKey()==13)
		//{
			//CLCD_voidWriteCmd(0b00000010);
		//}

	}


return 0;
}

