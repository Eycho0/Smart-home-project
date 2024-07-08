/*
 * I2C.h
 *
 *  Created on: Feb 3, 2024
 *      Author: olege
 */

#ifndef I2C_DRIVERS_I2C_H_
#define I2C_DRIVERS_I2C_H_

#include "I2C_private.h"
#include "I2C_registers.h"
#include "../DIO drivers/dio.h"

typedef enum
{
	NoError,
	Start_Condition_Error,
	Repeated_Start_Error,
	Slave_Address_With_Write_Error,
	Slave_Address_With_Read_Error,
	Master_Write_Byte_Error,
	Master_Read_Byte_Error

}I2C_Err_Status;

void I2C_vMasterInit(u8 Copy_u8SlaveAddress);

void I2C_vSlaveInit(u8 Copy_u8SlaveAddress);

I2C_Err_Status I2C_SendStartCondition(void);

I2C_Err_Status I2C_SendRepeatedStart(void);

I2C_Err_Status I2C_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);

I2C_Err_Status I2C_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);

I2C_Err_Status I2C_MasterWriteDataByte(u8 Copy_u8SlaveAddress);

I2C_Err_Status I2C_MasterReadDataByte(u8 *Copy_u8SlaveAddress);

void I2C_SendStopCondition(void);

#endif /* I2C_DRIVERS_I2C_H_ */
