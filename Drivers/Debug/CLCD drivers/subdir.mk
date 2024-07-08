################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CLCD\ drivers/CLCD.c 

OBJS += \
./CLCD\ drivers/CLCD.o 

C_DEPS += \
./CLCD\ drivers/CLCD.d 


# Each subdirectory must supply rules for building sources it contributes
CLCD\ drivers/CLCD.o: ../CLCD\ drivers/CLCD.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"CLCD drivers/CLCD.d" -MT"CLCD\ drivers/CLCD.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


