#define RCC_BASE_ADDRESS 	0x40021000

#define RCC_CR				*((32*)(RCC_BASE_ADDRESS + 0x00))//Processor clock
#define RCC_CFGR			*((32*)(RCC_BASE_ADDRESS + 0x04))//Processor clock
#define RCC_CIR				*((32*)(RCC_BASE_ADDRESS + 0x08))
#define RCC_APB2RSTR		*((32*)(RCC_BASE_ADDRESS + 0x0C))
#define RCC_APB1RSTR		*((32*)(RCC_BASE_ADDRESS + 0x10))
#define RCC_AHBENR			*((32*)(RCC_BASE_ADDRESS + 0x14))//Enable and disable peripheral
#define RCC_APB2ENR			*((32*)(RCC_BASE_ADDRESS + 0x18))//Enable and disable peripheral
#define RCC_APB1ENR			*((32*)(RCC_BASE_ADDRESS + 0x1C))//Enable and disable peripheral
#define RCC_BDCR			*((32*)(RCC_BASE_ADDRESS + 0x20))
#define RCC_CSR				*((32*)(RCC_BASE_ADDRESS + 0x24))