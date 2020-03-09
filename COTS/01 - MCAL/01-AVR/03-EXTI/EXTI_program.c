#include "EXTI_register.h"
/*MASKS*/
#define EXTI_SREG_GIE 			0b10000000//global interrupt enable pin

#define EXTI_MCUCR_ISC0			0b00000011//Interrupt sense control 0
#define EXTI_MCUCR_ISC0_LL		0b00000000
#define EXTI_MCUCR_ISC0_LCH		0b00000001
#define EXTI_MCUCR_ISC0_FE		0b00000010
#define EXTI_MCUCR_ISC0_RE		0b00000011

#define EXTI_MCUCR_ISC1			0b00001100//Interrupt sense control 1
#define EXTI_MCUCR_ISC1_LL		0b00000000
#define EXTI_MCUCR_ISC1_LCH		0b00000100
#define EXTI_MCUCR_ISC1_FE		0b00001000
#define EXTI_MCUCR_ISC1_RE		0b00001100


/*Functions*/
void EXTI_voidEnableGlobal(void)
{
	SET_BIT(SREG,7);
}

void EXTI_voidInt0Init(void)
{
	/*set sense control on falling edge*/
	Set_bit(mcucr,1);
	clr bit(mcucr,0)
	/*PIF for INT0*/
	set bit(gicr,6);
}
void EXTI_voidInt1Init(void)
{
	/*set sense control on falling edge*/
	Set_bit(mcucr,3);
	clr bit(mcucr,2)
	/*PIF for INT1*/
	set bit(gicr,7);
}
void EXTI_voidInt2Init(void)
{

}

