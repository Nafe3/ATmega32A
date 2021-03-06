/*
 * UART_Manager_program.c
 *
 *  Created on: Mar 11, 2020
 *      Author: moham
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"USART_interface.h"

#include"UART_Manager_interface.h"
#include"UART_Manager_config.h"
#include"USART_private.h"

UART_JobReq URTM_QUEUE[UARTM_u8_MAX_QUEUE_SIZE]		;
u8			URTM_QCurrent	=	0					;
u8			URTM_QNext	 	=	0					;
u8 			URTM_QAvailable	=UARTM_u8_MAX_QUEUE_SIZE;
u8 			URTM_BusyFlag 	= 	0					;

static void voidExecute(void);
static void voidStart(void);

u8 UARTM_performJobReq(UART_JobReq Copy_JobInfo)
{
	ErrorStatus Local_u8Status=STD_TYPES_ERROR_OK;
	/*Add the job to the queue*/
	if(URTM_QAvailable > 0)
	{
		URTM_QAvailable--;
		URTM_QUEUE[URTM_QNext]=Copy_JobInfo;

		/*Increment the next*/
		if( URTM_QNext == (UARTM_u8_MAX_QUEUE_SIZE-1))
		{
			URTM_QNext=0;
		}
		else
		{
			URTM_QNext++;
		}

		voidExecute();
	}
	else
	{
		Local_u8Status = STD_TYPES_ERROR_NOK;
	}
return Local_u8Status;

}

static void voidExecute(void)
{
	if(URTM_BusyFlag == 0)
	{
		voidStart();
	}
	else
	{
		/*Do nothing*/
	}
}
static void voidStart(void)
{

	u8 Local_u8Counter = 0;
	/*Check if Queue is empty*/
	if ( URTM_QAvailable == UARTM_u8_MAX_QUEUE_SIZE)
	{
		/*Do nothing*/
	}

	/*Queue includes jobs*/
	else
	{
		/*Start Job*/
		if(URTM_QAvailable == (UARTM_u8_MAX_QUEUE_SIZE-1))
		{
			switch(URTM_QUEUE[URTM_QCurrent].Jobtype)
			{
				case URTM_SEND_SYNC	:
					for( Local_u8Counter=0;Local_u8Counter < URTM_QUEUE[URTM_QCurrent].Length; Local_u8Counter++)
					{
						UART_voidTransmitDataSynch(URTM_QUEUE[URTM_QCurrent].DataBuffer[Local_u8Counter]);
					}
					URTM_QAvailable++;
					/*Increment the next*/
					if( URTM_QNext == (UARTM_u8_MAX_QUEUE_SIZE-1))
					{
						URTM_QNext=0;
					}
					else
					{
						URTM_QNext++;
					}

				break;

				case URTM_SEND_ASYNCH:
				break;

				case URTM_REC_SYNC:
				break;

				case URTM_REC_ASYNC:
				break;
			}
		}
		else
		{

		}
	}

}
