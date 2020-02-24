/*
 * main.c
 *
 *  Created on: Dec 4, 2019
 *      Author: Nafe3
 */

int main(void)
{
	SetPinDirection('D',7,1);
	SetPinDirection('D',6,1);
	SetPinDirection('D',5,1);
	SetPinDirection('D',4,1);
	SetPinDirection('D',3,1);



	while(1)
    {

		//1
		SetPinValue('D',7,1);
		SetPinValue('D',6,0);
		SetPinValue('D',5,0);
		SetPinValue('D',4,0);
		SetPinValue('D',3,0);
		for(double i=0;i<250;i++){}


		//2
		SetPinValue('D',7,0);
		SetPinValue('D',6,1);
		SetPinValue('D',5,1);
		SetPinValue('D',4,1);
		SetPinValue('D',3,1);
		for(double i=0;i<250;i++){}

		//3
		SetPinValue('D',7,0);
		SetPinValue('D',6,1);
		SetPinValue('D',5,0);
		SetPinValue('D',4,0);
		SetPinValue('D',3,0);
		for(double i=0;i<250;i++){}

		//4
		SetPinValue('D',7,1);
		SetPinValue('D',6,0);
		SetPinValue('D',5,1);
		SetPinValue('D',4,1);
		SetPinValue('D',3,1);
		for(double i=0;i<250;i++){}

		//5
		SetPinValue('D',7,0);
		SetPinValue('D',6,0);
		SetPinValue('D',5,1);
		SetPinValue('D',4,0);
		SetPinValue('D',3,0);
		for(double i=0;i<250;i++){}

		//6
		SetPinValue('D',7,1);
		SetPinValue('D',6,1);
		SetPinValue('D',5,0);
		SetPinValue('D',4,1);
		SetPinValue('D',3,1);
		for(double i=0;i<250;i++){}

		//7
		SetPinValue('D',7,0);
		SetPinValue('D',6,0);
		SetPinValue('D',5,0);
		SetPinValue('D',4,1);
		SetPinValue('D',3,0);
		for(double i=0;i<250;i++){}

		//8
		SetPinValue('D',7,1);
		SetPinValue('D',6,1);
		SetPinValue('D',5,1);
		SetPinValue('D',4,0);
		SetPinValue('D',3,1);
		for(double i=0;i<250;i++){}

		    }
}


