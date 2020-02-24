#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include<util/delay.h>
#include"DIO_interface.h"

#include"PORT_interface.h"

#include "LCD_private.h"
#include "LCD_config.h"
#include "LCD_interface.h"

int main (void)
{
	portInitialize();
	CLCD_voidInitialize();

	CLCD_voidWriteData('N');
	CLCD_voidWriteData('A');
	CLCD_voidWriteData('F');
	CLCD_voidWriteData('E');
	CLCD_voidWriteData('3');
	while(1);

return 0;
}
