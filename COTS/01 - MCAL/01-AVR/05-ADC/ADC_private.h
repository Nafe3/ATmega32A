#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

/*Bit Definitions for ADMUX Reg Pins*/
#define ADMUX_REFS1						7
#define ADMUX_REFS0						6
#define ADMUX_ADLAR						5



/*Bit Definitions for ADCSRA Pins*/
#define ADCSRA_ADEN 					7
#define ADCSRA_ADSC						6
#define ADCSRA_ADATE					5
#define ADCSRA_ADIF						4
#define ADCSRA_ADIE						3
#define ADCSRA_ADPS2					2
#define ADCSRA_ADPS1					1
#define ADCSRA_ADPS0					0

/*Macros for Resolution*/
 #define ADC_u8_8BIT_RESOLUTION			1
 #define ADC_u8_10BIT_RESOLUTION		2







#endif 
