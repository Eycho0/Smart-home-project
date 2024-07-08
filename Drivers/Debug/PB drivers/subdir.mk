################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../PB\ drivers/PB.c 

OBJS += \
./PB\ drivers/PB.o 

C_DEPS += \
./PB\ drivers/PB.d 


# Each subdirectory must supply rules for building sources it contributes
PB\ drivers/PB.o: ../PB\ drivers/PB.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"PB drivers/PB.d" -MT"PB\ drivers/PB.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


