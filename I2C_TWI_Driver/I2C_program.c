/*
 * I2C_program.c
 *
 *  Created on: Apr 8, 2020
 *      Author: moham
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "I2C_interface.h"
#include "I2C_private.h"
#include "I2C_config.h"
#include "I2C_register.h"

void I2C_voidMasterInit(void)
{
	/* Set frequency 400 KHz, prescaler value 0 */
	CLR_BIT(I2C_TWSR, I2C_TWSR_TWPS1);
	CLR_BIT(I2C_TWSR, I2C_TWSR_TWPS0);
	I2C_TWBR = 0x02;

	/*Enable I2C*/
	SET_BIT(I2C_TWCR, I2C_TWCR_TWEN);

	/*Enable ACK*/
	SET_BIT(I2C_TWCR, I2C_TWCR_TWEA);
}

void I2C_voidSlaveInit()
{
	/* */


	/*Enable I2C*/
	SET_BIT(I2C_TWCR, I2C_TWCR_TWEN);

	/*Enable ACK*/
	SET_BIT(I2C_TWCR, I2C_TWCR_TWEA);
}

void I2C_voidSendStartCondition(void)
{

}

void I2C_voidSendReStartCondition(void)
{

}

void I2C_voidSendSlaveAddWithWrite(u8 Copy_u8SlaveAdd)
{

}

void I2C_voidSendSlaveAddWithRead (u8 Copy_u8SlaveAdd)
{

}

void I2C_voidSendMasterDataByte(u8 Copy_u8Data)
{

}

void I2C_voidRecieveMasterDataByte(u8* Copy_u8Data)
{

}

void I2c_voidSendStopCondition(void)
{

}
