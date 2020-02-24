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
#include "KEYPAD_config.h"

#define home	0b00000010 //return to home
#define clear	0b00000001 //clear

#define screenUpperRigtLimit 0x0F
#define screenLowerRigtLimit 0x4F
#define screenUpperLeftLimit 0x00
#define screenLowerLeftLimit 0x40

#define default_Password	 1234

int main (void)
{
	portInitialize();
	CLCD_voidInitialize();

//	u8 ch=0b00110001;
//	u8 position=0;
	u8 key=0;
	//u8 Word[]={"Enter Password:"};
	u8 positions[4]={0x40,0x41,0x42,0x43};//first four location on the secind line
	u8 i=0;
	u8 length_counter=0;
	u8 pass[4]={0};
	u8 wrong_counter=0;
	while(1)
	{
		CLCD_voidWriteCmd(0b10000000|0x00);
		CLCD_voidWriteString("Enter Password:");
		key=KEYPAD_GetPressedKey();
		if(key!=KEYPAD_NOKEYPRESS)
		{
			if(i==0)
			{
				CLCD_voidWriteCmd(0b10000000|0x40);
				CLCD_voidWriteString("    ");
			}

			CLCD_voidWriteCmd(0b10000000|positions[i]);
			CLCD_voidWriteData('*');
			pass[i]=key;
			i++;
			length_counter++;
		}

		if(length_counter==4)
		{
			i=0;
			length_counter=0;
			if(pass[0]==1 && pass[1]==2 && pass[2]==3 && pass[3]==4)
			{
				CLCD_voidWriteCmd(0b10000000|0x46);
				CLCD_voidWriteString("           ");
				CLCD_voidWriteCmd(0b10000000|0x46);
				CLCD_voidWriteString("Correct");
			}
			else
			{
				wrong_counter++;
				CLCD_voidWriteCmd(0b10000000|0x46);
				CLCD_voidWriteString("           ");



				CLCD_voidWriteCmd(0b10000000|0x46);
				if(wrong_counter==3)
				{
					CLCD_voidWriteString("SystemLocked");
				}
				else{
				CLCD_voidWriteString("Trial ");
				CLCD_voidWriteData(wrong_counter+48);
				}
			}

		}

	}

return 0;
}
