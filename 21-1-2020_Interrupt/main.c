#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include<util/delay.h>
#include<stdio.h>

#include"DIO_interface.h"
#include"EXTI_interface.h"
#include"DIO_register.h"

void __vector_1(void)			__attribute__((signal));
void __vector_2(void)			__attribute__((signal));

int main (void)
{
	EXTI_voidEnableGlobal();
	EXTI_voidInt0Init();
	EXTI_voidInt1Init();
	EXTI_voidInt2Init();

	DIO_voidSetPinDir('D',0,1);//set D0 as output
	//DIO_voidSetPinVal('D',0,0);//set to low

	DIO_voidSetPinDir('D',2,0);//set D2(INT0) as input
	DIO_voidSetPinVal('D',2,1);//enable D2 pullup resistor

	DIO_voidSetPinDir('D',3,0);//set D3(INT1) as input
	DIO_voidSetPinVal('D',3,1);//enable pullup resistor

	/*
	DIO_voidSetPinDir('B',2,0);//set B2(INT2) as input
	DIO_voidSetPinVal('B',2,1);//enable pullup resistor
	*/
while(1);
	return 0;
}

/*EXT_INT0 -> button on PD2*/
void __vector_1(void)
{
	_delay_ms(100);
	CLR_BIT(PORTD,0);
}
/*EXT_INT1 -> button on PD3*/
void __vector_2(void)
{
	_delay_ms(100);
	SET_BIT(PORTD,0);
}


/*EXT_INT2 -> button on PB2
void __vector_3(void)
{
	_delay_ms(100);
	TGL_BIT(PORTD,0);
}
*/
