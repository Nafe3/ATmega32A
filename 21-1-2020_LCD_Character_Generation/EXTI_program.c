#include"STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_register.h"

/*MASKS*/
#define EXTI_SREG_GIE 			0b10000000//global interrupt enable pin

#define EXTI_MCUCR_ISC0			0b00000011//Interrupt 0 Sense Control
#define EXTI_MCUCR_ISC0_LL		0b00000000//The low level of INT0 generates an interrupt request.
#define EXTI_MCUCR_ISC0_LCH		0b00000001//Any logical change on INT0 generates an interrupt request.
#define EXTI_MCUCR_ISC0_FE		0b00000010//The falling edge of INT0 generates an interrupt request.
#define EXTI_MCUCR_ISC0_RE		0b00000011//The rising edge of INT0 generates an interrupt request.

#define EXTI_MCUCR_ISC1			0b00001100//Interrupt sense control 1
#define EXTI_MCUCR_ISC1_LL		0b00000000//The low level of INT1 generates an interrupt request.
#define EXTI_MCUCR_ISC1_LCH		0b00000100//Any logical change on INT1 generates an interrupt request.
#define EXTI_MCUCR_ISC1_FE		0b00001000//The falling edge of INT1 generates an interrupt request.
#define EXTI_MCUCR_ISC1_RE		0b00001100//The rising edge of INT1 generates an interrupt request.

#define EXTI_MCUCSR_ISC2  		0b01000000//Interrupt Sense Control 2
#define EXTI_MCUCSR_ISC2_FE		0b00000000//Falling edge
#define EXTI_MCUCSR_ISC2_RE		0b01000000//Rising Edge

#define EXTI_GICR_INT0			0b01000000;//External Interrupt Request 0 Enable
#define EXTI_GICR_INT1			0b10000000;//External Interrupt Request 1 Enable
#define EXTI_GICR_INT2			0b00100000;//External Interrupt Request 2 Enable

#define EXTI_GIFR_INTF			0b11100000;//INT0,1,2 EXTIFLAG
#define EXTI_GIFR_INTF0			0b01000000;//INTF0
#define EXTI_GIFR_INTF1			0b10000000;//INTF1
#define EXTI_GIFR_INTF2			0b00100000;//INTF2


/*Functions*/
void EXTI_voidEnableGlobal(void)
{
	/*set Global Interrupt Enable bit*/
	EXTI_SREG |= EXTI_SREG_GIE;
}

void EXTI_voidInt0Init(void)
{
	/*PIF for INT0*/
	EXTI_GICR  |= EXTI_GICR_INT0;
	//SET_BIT(EXTI_GICR,);
	/*set sense control 0 on falling edge*/
	EXTI_MCUCR &=~EXTI_MCUCR_ISC0;
	EXTI_MCUCR |= EXTI_MCUCR_ISC0_FE;
}
void EXTI_voidInt1Init(void)
{
	/*PIF for INT1*/
	EXTI_GICR  |= EXTI_GICR_INT1;
	/*set sense control 1 on falling edge*/
	EXTI_MCUCR &=~EXTI_MCUCR_ISC1;
	EXTI_MCUCR |= EXTI_MCUCR_ISC1_FE;
}
void EXTI_voidInt2Init(void)
{
	/*PIF for INT2*/
	EXTI_GICR    |= EXTI_GICR_INT2;
	/*clear Interrupt sense control 2 -> falling edge means clearing the bit*/
	EXTI_MCUCSR  &=~EXTI_MCUCSR_ISC2;

}
