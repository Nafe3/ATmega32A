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
//	u8 key=0;
	u8 Word[5]={'N','A','F','E','3'};
	u8 positions[5]={0x00,0x01,0x02,0x03,0x04};
	u8 i=0;
	u8 lineflag=0;

	u8 directionFlag=1;

	while(1)
	{
		/*
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
		}
		if(key==2)//shift the whole display right
		{
			CLCD_voidWriteCmd(0b10000000|0x41);
			CLCD_voidWriteData('N');
			_delay_ms(2000);
			CLCD_voidWriteCmd(0b10000000|0x41);
			CLCD_voidWriteData('A');
			_delay_ms(2000);
			CLCD_voidWriteCmd(0b10000000|0x02);
			CLCD_voidWriteData('F');
		}
		for(i=0;i<sizeof(Word)/sizeof(u8);i++)
		{
			CLCD_voidWriteCmd(0b10000000|0x00);
			CLCD_voidWriteData('N');
			_delay_ms(2000);
			CLCD_voidWriteCmd(0b10000000|0x41);
			CLCD_voidWriteData('A');
			_delay_ms(2000);
			CLCD_voidWriteCmd(0b10000000|0x02);
			CLCD_voidWriteData('F');
			_delay_ms(2000);
			CLCD_voidWriteCmd(0b10000000|0x43);
			CLCD_voidWriteData('E');
			_delay_ms(2000);
			CLCD_voidWriteCmd(0b10000000|0x04);
			CLCD_voidWriteData('3');
		}*/
		_delay_ms(4000);
		CLCD_voidWriteCmd(clear);
		for(i=0;i<sizeof(Word)/sizeof(u8);i++)
			{
			_delay_ms(100);
			CLCD_voidWriteCmd(0b10000000|positions[i]);
				CLCD_voidWriteData(Word[i]);
				//positions[i]=positions[i]+1;
				//_delay_ms(1000);
			}
		if(directionFlag){
			//move right
			if(lineflag)
			{
				positions[0]=positions[1];
				positions[1]=positions[2];
				positions[2]=positions[3];
				positions[3]=positions[4];
				positions[4]-=0x40;
				positions[4]++;
				lineflag=0;
			}
			else
			{
				positions[0]=positions[1];
				positions[1]=positions[2];
				positions[2]=positions[3];
				positions[3]=positions[4];
				positions[4]+=0x40;
				positions[4]++;
				lineflag=1;
			}

		}
		else{
			//move left
			if(lineflag)
			{
				positions[4]=positions[3];
				positions[3]=positions[2];
				positions[2]=positions[1];
				positions[1]=positions[0];
				positions[0]-=0x40;
				positions[0]--;
				lineflag=0;
			}
			else
			{
				positions[4]=positions[3];
				positions[3]=positions[2];
				positions[2]=positions[1];
				positions[1]=positions[0];
				positions[0]+=0x40;
				positions[0]--;
				lineflag=1;
			}

		}


/*
direction 1 -> right
direction 0 -> left
lineflag  1 -> bottom line
lineflag  0 -> upper line
*/
		//if((positions[4]<screenUpperLeftLimit)||(positions[4]<screenLowerLeftLimit))directionFlag=1;
		//if((positions[4]>screenUpperRigtLimit)||(positions[4]>screenLowerRigtLimit))directionFlag=0;
		if((lineflag==1)&&(positions[4]>screenLowerRigtLimit))directionFlag=0;
		else if((lineflag==1)&&(positions[0]<screenLowerLeftLimit))directionFlag=1;
		if((lineflag==0)&&(positions[4]>screenUpperRigtLimit))directionFlag=0;
		else if((lineflag==0)&&(positions[0]<screenUpperLeftLimit))directionFlag=1;
	}




return 0;
}

void snake(void)
{

}
void shiftLine(void)
{

}
