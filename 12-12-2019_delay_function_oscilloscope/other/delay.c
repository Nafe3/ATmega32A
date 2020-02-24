#define u8  unsigned char
#define u16 unsigned short int
#define u32 unsigned long int

#define s8  signed char
#define s16 signed short int
#define s32 signed long int

#define f32 float
#define f64 double
#define f96 long double

#define t1		(f32)			//loop iteration
#define t2		(f32)			//calculations
#define t3		(f32)			//context switching call
#define t4		(f32)			//context switching call

#define DDRA	*((volatile u8 *)(0x3A)) 
#define PORTA	*((volatile u8 *)(0x3B))

void Delay_ms(u32 value)
{
	//u32 i;
	//u32 count = (float)value -(t2+t3+t4)/t1;
	
	for(i=0;i<100;i++)
	{
		asm("NOP");
	}
}

void main(void)
{
	DDRA=ob00000001;
	while(1)
	{
		PORTA=1;
		Delay_ms(100);
	}
}