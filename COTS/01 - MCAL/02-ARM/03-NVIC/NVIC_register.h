/*Author: Mohamed Nafea		*/
/*Date:2/2/2020         	*/
/*Version:N01				*/


#ifndef NVIC_REGISTER_H
#define NVIC_REGISTER_H


/*Set Enable Register*/

#define NVIC_ISER0  ((volatile u32) 0xE00E100)
#define NVIC_ISER1  ((volatile u32) 0xE00E104)

/*Clear Enable Register */

#define NVIC_ICER0 	((volatile u32) 0xE00E180)
#define NVIC_ICER1 	((volatile u32) 0xE00E184)

/*Set Pending Flag*/
#define NVIC_ISPR0 	((volatile u32) 0xE00E200)
#define NVIC_ISPR1 	((volatile u32) 0xE00E204)


/*Clear Pending Flag*/

#define NVIC_ICPR0 	((volatile u32) 0xE00E280)
#define NVIC_ICPR1 	((volatile u32) 0xE00E284)


/*Get Avtive Flag*/

#define NVIC_IABR0 	((volatile u32) 0xE00E300)
#define NVIC_IABR1 	((volatile u32) 0xE00E304)

#endif