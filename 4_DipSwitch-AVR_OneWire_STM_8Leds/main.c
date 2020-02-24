/*
 * main.c
 *
 *  Created on: Jan 4, 2020
 *      Author: moham
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include <util/delay.h>
#include"DIO_interface.h"
#include"PORT_interface.h"

void startCom();//function to initialize the communication
void sendByte();//function that send the byte

void main(void)
{

	portInitialize();


	while(1)
	{
		if(getPinValue('D',3)==0)
			setPinValue('C',1,1);
		else
		{
			setPinValue('C',1,0);
		}

	//	startCom();
		//sendByte();
	}
}

void startCom()//function to initialize the communication
{
	setPinValue('A',7,0);
	//_delay_us(1000);
	setPinValue('A',7,1);
	//_delay_us(1000);
}

void sendByte()//function that send the byte
{
	setPinValue('A',7,getPinValue('A',0));
	setPinValue('A',7,getPinValue('A',1));
	setPinValue('A',7,getPinValue('A',2));
	setPinValue('A',7,getPinValue('A',3));
	setPinValue('A',7,getPinValue('A',4));
	setPinValue('A',7,getPinValue('A',5));
	setPinValue('A',7,getPinValue('A',6));
	setPinValue('A',7,getPinValue('A',7));
}
