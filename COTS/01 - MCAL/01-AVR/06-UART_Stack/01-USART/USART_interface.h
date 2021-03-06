/*********************************************************************/
/*Author	: Mohamed Nafea                                    		 */
/*Date 		: 9 March 2020											 */
/*Version	: V01													 */
/*********************************************************************/



#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_


void UART_voidInit(void);

ErrorStatus UART_voidTransmitDataSynch		(u8 Copy_u8Data);
void 		UART_voidTransmitDataAsynch		(u8 Copy_u8Data, void(*Copy_ptr)(void));

ErrorStatus UART_u8RecieveSynch				(u8* Copy_u8Data);
void 		UART_u8RecieveAsynch			(void(*Copy_ptr)(u8));


#endif 
