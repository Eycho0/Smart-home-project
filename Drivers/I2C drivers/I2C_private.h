#ifndef	I2C_PRIVATE_H
#define	I2C_PRIVATE_H

#define START_ACK					0X08
#define REP_START_ACK				0X10
#define	SLAVE_ADD_AND_W_ACK			0X18
#define	SLAVE_ADD_AND_R_ACK			0X40
#define	MASTER_W_BYTE_ACK			0X28
#define MASTER_R_BYTE_WITH_ACK		0X50
#define	MASTER_R_BYTE_WITH_NACK		0X58
#define	SLAVE_ADD_RCVD_R_REQ		0XA8
#define	SLAVE_ADD_RCVD_W_REQ		0X60
#define	SLAVE_DATA_RECEIVED			0X80
#define	SLAVE_BYTE_TRANSMITTED		0XB8

#endif