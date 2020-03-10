#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADC_u8CHANNEL_0			0
#define ADC_u8CHANNEL_1			1
#define ADC_u8CHANNEL_2			2
#define ADC_u8CHANNEL_3			3
#define ADC_u8CHANNEL_4			4
#define ADC_u8CHANNEL_5			5
#define ADC_u8CHANNEL_6			6
#define ADC_u8CHANNEL_7			7


void ADC_voidInit(void);
void ADC_StartConversion(u8 channel);
u8 	 ADC_u8GetChannelReading(u8 channel);








#endif 
