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


#define home	0b00000010
#define clear	0b00000001 //clear

#define screenUpperRigtLimit 0x0F
#define screenLowerRigtLimit 0x4F
#define screenUpperLeftLimit 0x00
#define screenLowerLeftLimit 0x40

int main (void)
{
	portInitialize();
	CLCD_voidInitialize();

//	u8 ch=0b00110001;
//	u8 position=0;
	u8 key=0;
	u8 Word[5]={'N','A','F','E','3'};
	u8 positions[5]={0x00,0x01,0x02,0x03,0x04};
	u8 i=0;
	u8 lineflag=2;
	u8 directionFlag=1;
	u8 static limitcounter=0;//dummiest way to control the screen limit

	while(1)
	{
		//CLCD_voidWriteCmd(clear);
		for(i=0;i<sizeof(Word)/sizeof(u8);i++)
		{
			CLCD_voidWriteCmd(0b10000000|positions[i]);
			CLCD_voidWriteData(Word[i]);
		}
		/*
		direction 1 -> right
		direction 0 -> left
		lineflag  1 -> bottom line
		lineflag  0 -> upper line
		*/
		key=KEYPAD_GetPressedKey();
		if(key==2)lineflag=0;						//up
		else if(key==6)lineflag=1;					//down
		else if(key==7)//right
			{
				if(limitcounter==11)
					continue;
				//CLCD_voidWriteCmd(0b00011100);//shifts all display to right
				CLCD_voidWriteCmd(clear);
				positions[0]++;
				positions[1]++;
				positions[2]++;
				positions[3]++;
				positions[4]++;
				limitcounter++;
				_delay_ms(10);
			}
		else if(key==5)
			{
				if(limitcounter==0)
					continue;
				CLCD_voidWriteCmd(clear);
				positions[0]--;
				positions[1]--;
				positions[2]--;
				positions[3]--;
				positions[4]--;
				//CLCD_voidWriteCmd(0b00011000);//shifts all display to left
				limitcounter--;
				_delay_ms(10);
			}
		//_delay_ms(4000);
		//CLCD_voidWriteCmd(clear);

			if(lineflag==1)
			{
				CLCD_voidWriteCmd(clear);
				positions[0]-=0x40;
				positions[1]-=0x40;
				positions[2]-=0x40;
				positions[3]-=0x40;
				positions[4]-=0x40;
				lineflag=2;
				_delay_ms(10);
			}
			else if(lineflag==0)
			{
				CLCD_voidWriteCmd(clear);
				positions[0]+=0x40;
				positions[1]+=0x40;
				positions[2]+=0x40;
				positions[3]+=0x40;
				positions[4]+=0x40;
				lineflag=2;
				_delay_ms(10);
			}

		/*
direction 1 -> right
direction 0 -> left
lineflag  1 -> bottom line
lineflag  0 -> upper line
*/

		if((lineflag==1)&&(positions[4]>screenLowerRigtLimit))directionFlag=0;
		else if((lineflag==1)&&(positions[0]<screenLowerLeftLimit))directionFlag=1;
		if((lineflag==0)&&(positions[4]>screenUpperRigtLimit))directionFlag=0;
		else if((lineflag==0)&&(positions[0]<screenUpperLeftLimit))directionFlag=1;
	}




return 0;
}
