/*
 * I2C_interface.h
 *
 *  Created on: Apr 8, 2020
 *      Author: moham
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

void I2C_voidMasterInit(void);

void I2C_voidSlaveInit(void);

void I2C_voidSendStartCondition(void);

void I2C_voidSendReStartCondition(void);

void I2C_voidSendSlaveAddWithWrite(u8 Copy_u8SlaveAdd);

void I2C_voidSendSlaveAddWithRead (u8 Copy_u8SlaveAdd);

void I2C_voidSendMasterDataByte(u8 Copy_u8Data);

void I2C_voidRecieveMasterDataByte(u8* Copy_u8Data);

void I2c_voidSendStopCondition(void);


#endif /* I2C_INTERFACE_H_ */
