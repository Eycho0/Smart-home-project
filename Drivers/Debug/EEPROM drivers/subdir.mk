################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../EEPROM\ drivers/EEPROM.c 

OBJS += \
./EEPROM\ drivers/EEPROM.o 

C_DEPS += \
./EEPROM\ drivers/EEPROM.d 


# Each subdirectory must supply rules for building sources it contributes
EEPROM\ drivers/EEPROM.o: ../EEPROM\ drivers/EEPROM.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"EEPROM drivers/EEPROM.d" -MT"EEPROM\ drivers/EEPROM.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


