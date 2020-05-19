/*
 * I2C_private.h
 *
 *  Created on: Apr 8, 2020
 *      Author: moham
 */

#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_

/* TWCR PINS */

#define I2C_TWCR_TWINT           7
#define I2C_TWCR_TWEA            6
#define I2C_TWCR_TWSTA           5
#define I2C_TWCR_TWSTO           4
#define I2C_TWCR_TWWC            3
#define I2C_TWCR_TWEN            2
#define I2C_TWCR_TWIE            0


/* TWSR PINS */
#define I2C_TWSR_TWPS1           1
#define I2C_TWSR_TWPS0           0

#define I2C_STATUS_CODE_MASK 	0XF8
/*Status Codes*/
/*Master Transmit*/

#define I2C_MT_SC_ACK		0x80
#define I2C_MT_RSC_ACK		0x10
#define I2C_MT_SLA_W_ACK	0x18	//Slave Address with write operation
#define I2C_MT_DATA_ACK		0x28


#endif /* I2C_PRIVATE_H_ */
