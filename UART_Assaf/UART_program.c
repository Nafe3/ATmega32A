/*****************************************************************/
/* Author    : Ahmed Assaf                                       */
/* Date      : 9 March 2020                                      */
/* Version   : V01                                               */
/*****************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_register.h"
#include "UART_private.h"
#include "UART_config.h"

const u8 BaudRateValue[3][3] =
{
	/*  4800    ,   9600   , 115200   */
	{   0x67    ,   0x33   ,  0x03     },  /* Clock System 0 = 8  MHz */
	{   154     ,     77   ,   6       },  /* Clock System 1 = 12 MHz */
	{   0xcf    ,   0x67   ,   0x08    }   /* Clock System 2 = 16 Mhz */
};


void (*EndOfTransmitCB)(void);
void (*EndOfRecCB)(u8  );

void UART_voidInitialize(void)
{
	/* U2X = 0 */
	CLR_BIT(UCSRA,1);
	
	/* Disable all UART Interrupts */
	/* Enable RX and TX */
	/* Character size 8 bit */
	UCSRB = 0x18;
	
	/* Asynch Mode
       Character size = 8 bit   	*/
    UCSRC = ( 
		     (1                 << 7) |
             (UART_u8_PARTIY    << 4) |
		     (UART_u8_STOP_BITS << 3) |
		     (3                 << 1) 
		    );
			
	/* Assign Buad Rate */
	UBRRL = BaudRateValue[UART_u8_SYS_FREQ][UART_u8_BUAD_RATE];
}

u8 UART_u8TransmitDataSynch   (u8 Copy_u8Data)
{
	u32 Local_u32Timeout = 0;
	u8  Local_u8Error    = STD_TYPES_ERROR_OK;
	
	/* Send data on UDR */
	UDR_T = Copy_u8Data;
	
	/* wait till flag is raised */
	while( (GET_BIT(UCSRA,6) == 0) && (Local_u32Timeout < UART_u32_TIME_OUT_TH))
	{
		Local_u32Timeout++;
	}
	
	/* timeout happened */
	if (Local_u32Timeout >= UART_u32_TIME_OUT_TH)
	{
		Local_u8Error = STD_TYPES_ERROR_NOK;
	}
	
	else
	{
		/* Clear Flag */
		SET_BIT(UCSRA,6);
	}
	
	return Local_u8Error;
}

void UART_voidTransmitDataAsynch  (u8 Copy_u8Data, void(*Copy_ptr)(void))
{
	/* Enable Tx Interrupt */
	SET_BIT(UCSRB,6);
	
	/* Set recieved Data to UDR */
	UDR_T = Copy_u8Data;
	
	/* Save the callback address */
	EndOfTransmitCB = Copy_ptr;
}

u8     UART_u8ReceiveSynch  (u8* Copy_pu8Data)
{
	u32 Local_u32Timeout = 0;
	u8  Local_u8Error    = STD_TYPES_ERROR_OK;
	
	/* wait till flag is raised */
	while( (GET_BIT(UCSRA,7) == 0) && (Local_u32Timeout < UART_u32_TIME_OUT_TH))
	{
		Local_u32Timeout++;
	}
	
	/* timeout happened */
	if (Local_u32Timeout >= UART_u32_TIME_OUT_TH)
	{
		Local_u8Error = STD_TYPES_ERROR_NOK;
	}
	
	else
	{
		/* Set data to recived pointer */
		*Copy_pu8Data = UDR_R;
	}
	
	return Local_u8Error;
}

void   UART_u8ReceiveAsynch ( void(*Copy_ptr)(u8) )
{
	/* Check if there is data to receive */
	if ( GET_BIT(UCSRA,7) == 1)
	{
		Copy_ptr(UDR_R);
	}
	
	/* Nothing to receive now, enable recieve interrupt */
	else
	{
		/* Enable Rx Interrupt */
		SET_BIT(UCSRB,7);
		
		/* Save call back in global variable */
		EndOfRecCB = Copy_ptr;
		
	}
}
