/*
 * main.c
 *
 *  Created on: Mar 11, 2020
 *      Author: moham
 */

#include"STD_TYPES.h"
#include"USART_interface.h"
#include"UART_Manager_interface.h"
void main(void)
{
	//1.write
	u8  Arr[]="Ahmed";
	UART_JobReq Job1={0,Arr,6,STD_NULL};
	void UARTM_performJobReq(Job1);

	//2.Read
	u8 Arr[10];
	UART_JobReq Job2={2,Arr,10,STD_NULL};

	//3. Write Asynch
	u8 Arr[]="Ahmed"
	void func(void)
	{
		/*Turn on led*/
	}
	UART_JobReq Job3={1,Arr,6,func};
	void UARTM_performJobReq(Job3);

	//4.Read Asynch
	u8 Arr[10];
	void func(void)
	{

	}
	void UARTM_performJobReq(Job4);
}
