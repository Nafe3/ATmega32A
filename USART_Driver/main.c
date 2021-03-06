/*
 * main.c
 *
 *  Created on: Mar 9, 2020
 *      Author: Mohamed Nafea
 */
#include"STD_TYPES.h"

#include "DIO_interface.h"
#include "USART_interface.h"
#include "LCD_interface.h"



void recievefunc(u8 RecievedByte)
{
	//CLCD_voidWriteCmd(0b00000001);//clear screen
	CLCD_voidWriteData(RecievedByte);
}

int main(void)
{
	setPinDir('D',0,0);//Rx
	setPinDir('D',1,1);//Tx

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
	UART_voidInit();


	while(1)
	{
		UART_u8RecieveAsynch (recievefunc);
	}
}
