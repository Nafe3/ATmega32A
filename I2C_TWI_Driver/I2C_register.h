/*
 * I2C_register.h
 *
 *  Created on: Apr 8, 2020
 *      Author: moham
 */

#ifndef I2C_REGISTER_H_
#define I2C_REGISTER_H_

#define I2C_TWDR  *((volatile u8*)0x23)
#define I2C_TWAR  *((volatile u8*)0x22)
#define I2C_TWSR  *((volatile u8*)0x21)
#define I2C_TWBR  *((volatile u8*)0x20)
#define I2C_TWCR  *((volatile u8*)0x56)

#endif /* I2C_REGISTER_H_ */
