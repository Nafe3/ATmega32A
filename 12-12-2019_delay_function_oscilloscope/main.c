#define u8  unsigned char
#define u16 unsigned short int
#define u32 unsigned long int

#define s8  signed char
#define s16 signed short int
#define s32 signed long int

#define f32 float
#define f64 double
#define f96 long double

//#define t1		(f32)0.033875      		//loop iteration
#define t1		0.004375    		//loop iteration
#define t       0.009605
#define t2		(f32)2.199875			//calculations
#define t3		(f32)0.032875			//context switching call
#define t4		(f32)0.018675    		//context switching return
#define t5		(f32)3.25`
#define DDRA	*((volatile u8*)0x3A)
#define PORTA	*((volatile u8*)0x3B)

void Delay_ms(u32 value)
{
	u32 i;
	u32 count = (value -t)/t1;

	for(i=0;i<count;i++)
	{
		asm("NOP");
	}
}

void main(void)
{
	DDRA=0b00000001;
	while(1)
	{
		PORTA=0b00000001;
		Delay_ms(100);
		PORTA=0b00000000;
		Delay_ms(100);
	}
}

