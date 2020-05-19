/*
 * main.c
 *
 *  Created on: Apr 6, 2020
 *      Author: moham
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "UART_interface.h"

#include <util/delay.h>


void func(void)
{
	static u8 flag = 0;
	if(flag ==0)
	{
		setPinValue('D',2,0);//LED OFF
		flag = 1 ;
	}
	else if(flag == 1 )
	{
		setPinValue('D',2,1);//LED OFF
		flag = 0 ;
	}
}


int main(void)
{
	setPinDir('D',0,0);//Rx
	setPinDir('D',1,1);//Tx
	setPinDir('D',2,1);//LED

	UART_voidInitialize();

	//Enable Global Interrupt
	u8 counter = 0;
	u8 Arr[] = "Nafea\n";

	u8 Recieve_data;
	while(1)
	{
	/*	while(Arr[counter] != '\0')
		{
			UART_u8TransmitDataSynch(Arr[counter]);
			counter++;
		}
		counter = 0;
		_delay_ms(1000);*/

	/*	UART_u8ReceiveSynch(&Recieve_data);
		if(Recieve_data == 'a')
		{
			setPinValue('D',2,1);//LED ON
		}
		else if(Recieve_data == 'b')
		{
			setPinValue('D',2,0);//LED OFF
		}
*/
		while(Arr[counter] != '\0')
		{
			UART_voidTransmitDataAsynch(Arr[counter], &func);
			_delay_ms(1000);
			counter++;
		}
		counter = 0 ;
	}
return 0;
}
