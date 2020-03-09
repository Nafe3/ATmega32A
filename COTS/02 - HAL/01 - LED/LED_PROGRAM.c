#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "LED_INTERFACE.h"
#include "LED_PRIVATE.h"
#include "LED_CONFIG.h"


void setLedOn  (void)
{
	setPinValue(LED_Port, LED_Pin, LED_Mode);
}

void setLedOff (void)
{
	setPinValue(LED_Port, LED_Pin, LED_Mode^1);
}