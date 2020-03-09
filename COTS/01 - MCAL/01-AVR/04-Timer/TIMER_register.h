#ifndef Timer_REGISTER_H_
#define Timer_REGISTER_H_

#define TCCR0  *((volatile u8)* 0x53)
#define TCNT0  *((volatile u8)* 0x52)
#define TIMSK0 *((volatile u8)* 0x59)
#define TIFR0  *((volatile u8)* 0x58)
#define SREG   *((volatile u8)* 0x5F)


#endif 