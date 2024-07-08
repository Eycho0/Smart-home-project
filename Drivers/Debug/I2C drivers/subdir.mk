################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../I2C\ drivers/I2C.c 

OBJS += \
./I2C\ drivers/I2C.o 

C_DEPS += \
./I2C\ drivers/I2C.d 


# Each subdirectory must supply rules for building sources it contributes
I2C\ drivers/I2C.o: ../I2C\ drivers/I2C.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"I2C drivers/I2C.d" -MT"I2C\ drivers/I2C.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


