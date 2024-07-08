################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LED\ drivers/LED.c 

OBJS += \
./LED\ drivers/LED.o 

C_DEPS += \
./LED\ drivers/LED.d 


# Each subdirectory must supply rules for building sources it contributes
LED\ drivers/LED.o: ../LED\ drivers/LED.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"LED drivers/LED.d" -MT"LED\ drivers/LED.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


