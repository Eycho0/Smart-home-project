/*
 * I2C.c
 *
 *  Created on: Feb 3, 2024
 *      Author: olege
 */

#include "I2C.h"

void I2C_vMasterInit(u8 Copy_u8SlaveAddress)
{
	/*Set clk to 400kbps*/
	TWDR=2;
	CLR_BIT(TWSR,TWSR_TWPS0);
	CLR_BIT(TWSR,TWSR_TWPS1);

	if(Copy_u8SlaveAddress != 0)
	{
		TWAR = Copy_u8SlaveAddress<<1;
	}

	/*Enable I2C*/
	SET_BIT(TWCR,TWCR_TWEN);
}

void I2C_vSlaveInit(u8 Copy_u8SlaveAddress)
{
	/*Initialize adress*/
	TWAR = Copy_u8SlaveAddress<<1;

	/*Enable I2C*/
	SET_BIT(TWCR,TWCR_TWEN);
}

I2C_Err_Status I2C_SendStartCondition(void)
{
	I2C_Err_Status Local_Error_status= NoError;

	/*Send start condition*/
	SET_BIT(TWCR,TWCR_TWSTA);

	/*clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*Wait until the interrupt flag is raised again*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);

	/*Check on operation*/
	if((TWSR & 0xF8)!= START_ACK)
	{
		Local_Error_status = Start_Condition_Error;
	}
	else
	{
		/*do nothing*/
	}
	return Local_Error_status;
}

I2C_Err_Status I2C_SendRepeatedStart(void)
{
	I2C_Err_Status Local_Error_status= NoError;

	/*Send start condition*/
	SET_BIT(TWCR,TWCR_TWSTA);

	/*clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*Wait until the interrupt flag is raised again*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);

	/*Check on operation*/
	if((TWSR & 0xF8)!= REP_START_ACK)
	{
		Local_Error_status = Repeated_Start_Error;
	}
	else
	{
		/*do nothing*/
	}
	return Local_Error_status;

}

I2C_Err_Status I2C_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
	I2C_Err_Status Local_Error_status= NoError;

	/*Clear start condition bit*/
	CLR_BIT(TWCR,TWCR_TWSTA);

	/*Set the slave address in the 7 MSB IN TWDR*/
	TWDR = Copy_u8SlaveAddress<<1;
	CLR_BIT(TWDR,0); //for write

	/*clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*Wait until the interrupt flag is raised again*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);

	/*Check on operation*/
	if((TWSR & 0xF8)!= SLAVE_ADD_AND_W_ACK)
	{
		Local_Error_status = Slave_Address_With_Write_Error;
	}
	else
	{
		/*do nothing*/
	}

	return Local_Error_status;
}

I2C_Err_Status I2C_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress)
{
	I2C_Err_Status Local_Error_status= NoError;

	/*Clear start condition bit*/
	CLR_BIT(TWCR,TWCR_TWSTA);

	/*Set the slave address in the 7 MSB IN TWDR*/
	TWDR = Copy_u8SlaveAddress<<1;
	SET_BIT(TWDR,0); //for read

	/*clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*Wait until the interrupt flag is raised again*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);

	/*Check on operation*/
	if((TWSR & 0xF8)!= SLAVE_ADD_AND_R_ACK)
	{
		Local_Error_status = Slave_Address_With_Read_Error;
	}
	else
	{
		/*do nothing*/
	}

	return Local_Error_status;
}

I2C_Err_Status I2C_MasterWriteDataByte(u8 Copy_u8SlaveAddress)
{
	I2C_Err_Status Local_Error_status= NoError;

	/*Write data byte*/
	TWDR = Copy_u8SlaveAddress;

	/*clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*Wait until the interrupt flag is raised again*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);

	/*Check on operation*/
	if((TWSR & 0xF8)!= MASTER_W_BYTE_ACK)
	{
		Local_Error_status = Master_Write_Byte_Error;
	}
	else
	{
		/*do nothing*/
	}


	return Local_Error_status;
}

I2C_Err_Status I2C_MasterReadDataByte(u8 *Copy_u8SlaveAddress)
{
	I2C_Err_Status Local_Error_status= NoError;

	/*Enable master generating acknowledge bit after receiving the data*/
	SET_BIT(TWCR,TWCR_TWEA);

	/*clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*Wait until the interrupt flag is raised again*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);

	/*Check on operation*/
	if((TWSR & 0xF8)!= MASTER_R_BYTE_WITH_ACK)
	{
		Local_Error_status = Master_Read_Byte_Error;
	}
	else
	{
		*Copy_u8SlaveAddress = TWDR;
	}
	return Local_Error_status;
}

void I2C_SendStopCondition(void)
{
	/*Generate the stop condition*/
	SET_BIT(TWCR,TWCR_TWSTO);

	/*clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);
}
