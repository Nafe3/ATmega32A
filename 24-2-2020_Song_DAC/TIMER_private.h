#ifndef Timer_PRIVATE_H_
#define Timer_PRIVATE_H_

//Macros of the register pins instead pr writing them directly in the interface
//Protypes of ISR fucntions
#define PRELOAD_Value 131

void __vector_11(void) __attribute__((signal));

#endif 