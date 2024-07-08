################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sev_Seg\ drivers/sev_seg.c 

OBJS += \
./Sev_Seg\ drivers/sev_seg.o 

C_DEPS += \
./Sev_Seg\ drivers/sev_seg.d 


# Each subdirectory must supply rules for building sources it contributes
Sev_Seg\ drivers/sev_seg.o: ../Sev_Seg\ drivers/sev_seg.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"Sev_Seg drivers/sev_seg.d" -MT"Sev_Seg\ drivers/sev_seg.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


