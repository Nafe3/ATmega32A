#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER_interface.h"
#include "TIMER_private.h"
#include "TIMER_config.h"
#include "TIMER_register.h"

static void (*Timer0_Pfunc)(void);

void Timer0_voidInit(void)
{
  //Set Mode -> Normal Mode 
  CLR_BIT(TCCR0,6);
  CLR_BIT(TCCR0,8);
  //Enable OVF Interrupt
  SET_BIT(TIMSK,0);
  //Enable Global Interrupt
  //Set PreLoad Value
  // Set Prescaler Value
  SET_BIT(TMSK,0);
  //Call Global interupt enable function
  //TCNT0= preload
  //Set Prescaler - > 64
  CLR_BIT(TCCR0,2);
  SET_BIT(TCCR0,1);
  SET_BIT(TCCR0,0);
}

void Timer0_voidSetCallback(void (*PFunc)(void))
{
  Timer0_Pfunc=PFunc;
}

void __vector_11(void) // -> bteegy kol 1msec
{
  static u16 Local_u16Counter;
  Local_u16Counter++;
  if (Local_u16Counter == 1000)
  {
    Timer0_Pfunc();
    Local_u16Counter = 0;
  }
  TCNT0 = PRELOAD_Value; //Preload Value
}