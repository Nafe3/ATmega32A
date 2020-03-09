#include "STD_TYPES"

void delay_ms(u32 value)
{
	u32 i;
	u32 count = (value - Tm )/Tloop;
	for (i=0;i<100;i++)
	{
		asm("NOP);
	}
}