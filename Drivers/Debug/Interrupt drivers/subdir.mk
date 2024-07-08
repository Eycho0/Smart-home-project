################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Interrupt\ drivers/Interrupt.c 

OBJS += \
./Interrupt\ drivers/Interrupt.o 

C_DEPS += \
./Interrupt\ drivers/Interrupt.d 


# Each subdirectory must supply rules for building sources it contributes
Interrupt\ drivers/Interrupt.o: ../Interrupt\ drivers/Interrupt.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"Interrupt drivers/Interrupt.d" -MT"Interrupt\ drivers/Interrupt.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


