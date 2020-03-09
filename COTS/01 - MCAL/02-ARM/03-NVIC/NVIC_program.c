/*Author	: Mohamed Nafea		*/
/*Date  	: 2/2/2020        	*/
/*Version	: V01				*/

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "NVIC_register.h"
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void NVIC_voidEnableExtInt(u8 Copy_u8Idx)
{
    if(Copy_u8Idx <=31)
    {
      Set_Bit(NVIC_ISER0,Copy_u8Idx);
    }
    else if(Copy_u8Idx <=59)
    {
       Copy_u8Idx-=32;
       Set_Bit(NVIC_ISER1,Copy_u8Idx);
    }
}

void NVIC_voidDisableExtInt(u8 Copy_u8Idx)
{
    if(Copy_u8Idx <=31)
    {
      Set_Bit(NVIC_ICER0,Copy_u8Idx);
    }
    else if(Copy_u8Idx <=59)
    {
       Copy_u8Idx-=32;
       Set_Bit(NVIC_ICER1,Copy_u8Idx);
    }
}

void NVIC_voidSetPendingFlag(u8 Copy_u8Idx)
{
    if(Copy_u8Idx <=31)
    {
      Set_Bit(NVIC_ISPR0,Copy_u8Idx);
    }
    else if(Copy_u8Idx <=59)
    {
       Copy_u8Idx-=32;
       Set_Bit(NVIC_ISPR1,Copy_u8Idx);
    }
}

void NVIC_voidClrPendingFlag(u8 Copy_u8Idx)
{
    if(Copy_u8Idx <=31)
    {
      Set_Bit(NVIC_ICPR0,Copy_u8Idx);
    }
    else if(Copy_u8Idx <=59)
    {
       Copy_u8Idx-=32;
       Set_Bit(NVIC_ICPR1,Copy_u8Idx);
    }
}

u8 NVIC_u8GetActiveFlag(u8 Copy_u8Idx)
{
    u8 Local_U8Result;
    if(Copy_u8Idx <=31)
    {
      Local_U8Result=GET_BIT(NVIC_IABR0,Copy_u8Idx);
    }
    else if(Local_U8Result <=59)
    {
       Local_U8Result-=32;
       Local_U8Result=GET_BIT(NVIC_IABR1,Copy_u8Idx);
    }
}
