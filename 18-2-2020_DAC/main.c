/*
 * main.c
 *
 *  Created on: Feb 18, 2020
 *      Author: moham
 */
#include <util/delay.h>
#include"STD_TYPES.h"
#include"DIO_register.h"
int main(void)
{
DDRD=0xff;

while(1)
{
	u16 i;

for(i=0;i<=255;i++)
{
	PORTD=i;
	_delay_ms(10);
}
for(i=255;i>1;i--)
{
	PORTD=i;
	_delay_ms(10);
}


}
}

