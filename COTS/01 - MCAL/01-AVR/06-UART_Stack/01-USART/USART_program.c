#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_register.h"

#include "USART_config.h"
#include "USART_private.h"


//Callback functions
void (*EndofTransmitCB)(void);
void (*EndofRECCB)(u8);

//Lookup table
const u8 BaudRateValue[3][3] =
{
		/*4800 	,	9600	,	115200*/
		{0x67	,	0x33	,	0x03		},			/*Clock System 0 = 8  MHz*/
		{154	,	77		,	6			},			/*Clock System 0 = 12 MHz*/
		{0xCF	,	0x67	,	0x08		}			/*Clock System 0 = 16 MHz*/
};


void UART_voidInit(void)
{
	/*U2X = 0*/
	CLR_BIT(UCSRA,1);

	/*Disable all UART interrupts*/
	/*Enable RX and TX*/
	/*Character size 8 bit*/
	UCSRB=0x18;

	/*Asynch Mode
	 * Character size = 8 bit */
	UCSRC=	(
			  (1<<7)					|
			  (UART_u8_PARITY	<<	4)	|
			  (UART_u8_STOP_BITS<<	3)	|
			  (3				<<  1)
			);
	/*Assign Baud Rate*/
	UBRRL=BaudRateValue[UART_u8_SYS_FREQ ][UART_u8_BAUDRATE];
}
ErrorStatus UART_voidTransmitDataSynch		(u8 Copy_u8Data)
{
	u32 Local_u32Timeout = 0;
	u8  Local_u8Error	 = 0;

	/*Send data on UDR*/
	UDR_T	=	Copy_u8Data;

	/*wait till the flag is raised*/
	while ((!(GET_BIT(UCSRA,6)) && Local_u32Timeout < UART_u32_TIME_OUT))
	{
		Local_u32Timeout++;
	}

	/* TimeOUT happened */
		if(Local_u32Timeout >= UART_u32_TIME_OUT)
		{
			Local_u8Error = STD_TYPES_ERROR_NOK ;
		}
		else
		{
			CLR_BIT(UCSRA,6);
		}
		return Local_u8Error;

}

ErrorStatus   UART_u8RecieveSynch	(u8* Copy_u8Data)
{
	u32 		Local_u32TimeOut=	0;
	ErrorStatus Local_u8Status	=	STD_TYPES_ERROR_OK ;

	/* send data on UDR */
	UDR_T = *Copy_u8Data;

	/*Wait until */
	while (!(GET_BIT(UCSRA,6)) && Local_u32TimeOut < UART_u32_TIME_OUT)
	{
		Local_u32TimeOut++;
	}
	/* TimeOUT happened */
	if(Local_u32TimeOut >= UART_u32_TIME_OUT)
	{
		Local_u8Status = STD_TYPES_ERROR_NOK ;
	}
	else
	{
		*Copy_u8Data = UDR_R;
	}
	return Local_u8Status;
}


void UART_voidTransmitDataAsynch	(u8 Copy_u8Data, void(*Copy_ptr)(void))
{
	/* Disable interrupt */
	SET_BIT(UCSRB,6);

	/* Set recieved data  */
	UDR_T=Copy_u8Data;

	/*save the callback address */
	EndofTransmitCB=Copy_ptr;
}


void UART_u8RecieveAsynch	(void(*Copy_ptr)(u8))
{
	if(GET_BIT(UCSRA,7) ==1)
	{
		Copy_ptr(UDR_R);
	}
	else
	{
		SET_BIT(UCSRB,7);

		EndofRECCB=Copy_ptr;
	}
}
