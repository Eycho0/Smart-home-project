################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Timer\ drivers/Timer.c 

OBJS += \
./Timer\ drivers/Timer.o 

C_DEPS += \
./Timer\ drivers/Timer.d 


# Each subdirectory must supply rules for building sources it contributes
Timer\ drivers/Timer.o: ../Timer\ drivers/Timer.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"Timer drivers/Timer.d" -MT"Timer\ drivers/Timer.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


