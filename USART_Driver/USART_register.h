#ifndef USART_REGISTER_H_
#define USART_REGISTER_H_

#define UBRRH 		*((volatile u8*)0x40)
#define UCSRC 		*((volatile u8*)0x40)
#define UDR_T	  	*((volatile u8*)0x2C)
#define UDR_R	  	*((volatile u8*)0x2C)
#define UCSRA 		*((volatile u8*)0x2B)
#define UCSRB 		*((volatile u8*)0x2A)
#define UBRRL 		*((volatile u8*)0x29)

#endif 
