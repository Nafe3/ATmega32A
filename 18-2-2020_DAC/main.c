/*
 * main.c
 *
 *  Created on: Feb 18, 2020
 *      Author: moham
 */

#include"STD_TYPES.h"
#include"DIO_register.h"
void main(void)
{
DDRA=0xff;

while(1)
{
	u8 i;
for(i=0;i<16;i++)
{
	PORTA=i;
}
for(i=0;i<16;i++)
{
	PORTA=16-i;
}
}
}

