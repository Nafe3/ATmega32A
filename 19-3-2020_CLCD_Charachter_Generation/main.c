#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "util/delay.h"

int main (void)
{

	//CLCD Pins
	setPinDir('B',0,1);//D0
	setPinDir('B',1,1);//D1
	setPinDir('B',2,1);//D2
	setPinDir('B',3,1);//D3
	setPinDir('B',4,1);//D4
	setPinDir('B',5,1);//D5
	setPinDir('B',6,1);//D6
	setPinDir('B',7,1);//D7

	setPinDir('A',0,1);//E
	setPinDir('A',1,1);//RW
	setPinDir('A',2,1);//RS

	CLCD_voidInitialize();
	u8 CArr[8][8]=	{
						///////1
						{0b01110
						,0b01110
						,0b01110
						,0b00100
						,0b01110
						,0b10101
						,0b01010
						,0b10001},
						/////////2
						{0b01110,
						 0b01110,
						 0b01110,
						 0b10101,
						 0b01110,
						 0b00100,
						 0b01010,
						 0b10001},
						 /////////3
						 {0b00000,
						  0b00000,
						  0b00000,
						  0b01110,
						  0b01110,
						  0b01110,
						  0b00000,
						  0b00000 },
						///////////4
						{0b01110,
						 0b01110,
						 0b01110,
						 0b00100,
						 0b01110,
						 0b00100,
						 0b01011,
						 0b10001 },
						///////////5
						{0b01110,
					     0b01110,
					     0b01110,
					     0b00100,
					     0b01111,
					     0b00100,
					     0b01010,
						 0b10001},
						///////////6(hazza shmal)
							{0b01110,
							 0b01110,
							 0b01110,
							 0b10101,
							 0b01110,
							 0b01000,
							 0b01010,
							 0b10001},
						///////////7(hazza ymeen)
								{0b01110,
								 0b01110,
								 0b01110,
								 0b10101,
								 0b01110,
								 0b00010,
								 0b01010,
								 0b10001},
						///////////8
						{
						}
					};



	CLCD_voidGenerateCharachter(CArr);
	//1 standing arms down
	 // CLCD_voidWriteData(0b01110);
	 // CLCD_voidWriteData(0b01110);
	 // CLCD_voidWriteData(0b01110);
	 // CLCD_voidWriteData(0b00100);
	 // CLCD_voidWriteData(0b01110);
	 // CLCD_voidWriteData(0b10101);
	 // CLCD_voidWriteData(0b01010);
	 // CLCD_voidWriteData(0b10001);
	  //2 standing arms up
	//   0b01110,
	//   0b01110,
	//   0b01110,
	//   0b10101,
	//   0b01110,
	//   0b00100,
	//   0b00100,
	//   0b00100
	//   //3 ball
	//     0b00000,
	//     0b00000,
	//     0b00000,
	//     0b01110,
	//     0b01110,
	//     0b01110,
	//     0b00000,
	//     0b00000
	//	 //4 ball pos 1
	//	   0b01110,
	//	   0b01110,
	//	   0b01110,
	//	   0b00100,
	//	   0b01110,
	//	   0b00100,
	//	   0b01011,
	//	   0b10001
	//	 //5 ball pos 2
    // 	   0b01110,
	//	   0b01110,
	//	   0b01110,
	//	   0b00100,
	//	   0b01111,
	//     0b00100,
	//	   0b01010,
	//	   0b10001
	//		//6 ball pos 3
	//			 B01110,
	//			   B01110,
	//			   B01111,
	//			   B00100,
	//			   B01110,
	//			   B00100,
	//			   B01010,
	//			   B10001





	  //CLCD_voidWriteData(2);
	  //CLCD_voidWriteData(3);
	  //CLCD_voidWriteData(4);
	  //CLCD_voidWriteData(5);
	  //CLCD_voidWriteData(6);
	  //CLCD_voidWriteData(7);





	  while(1)
	{
		  CLCD_voidWriteCmd(CLCD_CMD_SET_DDRAM_ADDRESS|screenUpperLeftLimit);
		  CLCD_voidWriteData(1);
		  _delay_ms(200);
		  CLCD_voidWriteCmd(CLCD_CMD_SET_DDRAM_ADDRESS|screenUpperLeftLimit);
		  CLCD_voidWriteData(5);
		  _delay_ms(200);
		  CLCD_voidWriteCmd(CLCD_CMD_SET_DDRAM_ADDRESS|screenUpperLeftLimit);
		  CLCD_voidWriteData(1);
		  _delay_ms(200);
		  CLCD_voidWriteCmd(CLCD_CMD_SET_DDRAM_ADDRESS|screenUpperLeftLimit);
		  CLCD_voidWriteData(6);
		  _delay_ms(200);
	}
return 0;
}
