################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../UART\ drivers/UART.c 

OBJS += \
./UART\ drivers/UART.o 

C_DEPS += \
./UART\ drivers/UART.d 


# Each subdirectory must supply rules for building sources it contributes
UART\ drivers/UART.o: ../UART\ drivers/UART.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"UART drivers/UART.d" -MT"UART\ drivers/UART.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


