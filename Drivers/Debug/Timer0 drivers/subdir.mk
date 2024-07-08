################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Timer0\ drivers/Timer0.c 

OBJS += \
./Timer0\ drivers/Timer0.o 

C_DEPS += \
./Timer0\ drivers/Timer0.d 


# Each subdirectory must supply rules for building sources it contributes
Timer0\ drivers/Timer0.o: ../Timer0\ drivers/Timer0.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"Timer0 drivers/Timer0.d" -MT"Timer0\ drivers/Timer0.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


