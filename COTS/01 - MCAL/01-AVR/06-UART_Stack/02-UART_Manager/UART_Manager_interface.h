/*
 * UART_Manager_interface.h
 *
 *  Created on: Mar 11, 2020
 *      Author: moham
 */

#ifndef UART_MANAGER_INTERFACE_H_
#define UART_MANAGER_INTERFACE_H_

#define URTM_SEND_SYNC	   	0
#define URTM_SEND_ASYNCH  	1
#define URTM_REC_SYNC     	2
#define URTM_REC_ASYNC		3

typedef struct
{
	u8 		Jobtype				;
	u8*		DataBuffer			;
	u8 		Length				;
	void 	(*Callback)(void)	;
}UART_JobReq;



u8 UARTM_u8performJobReq(UART_JobReq Copy_JobInfo);

#endif /* UART_MANAGER_INTERFACE_H_ */
