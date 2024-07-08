################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Keypad\ drivers/Keypad.c 

OBJS += \
./Keypad\ drivers/Keypad.o 

C_DEPS += \
./Keypad\ drivers/Keypad.d 


# Each subdirectory must supply rules for building sources it contributes
Keypad\ drivers/Keypad.o: ../Keypad\ drivers/Keypad.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"Keypad drivers/Keypad.d" -MT"Keypad\ drivers/Keypad.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


