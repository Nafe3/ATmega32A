################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/ITI/Subjects/Intro\ to\ ES-Assaf/Tools/workspace_AVR/COTS/01\ -\ MCAL/01-AVR/05-ADC/ADC_program.c \
../main.c 

OBJS += \
./ADC_program.o \
./main.o 

C_DEPS += \
./ADC_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
ADC_program.o: D:/ITI/Subjects/Intro\ to\ ES-Assaf/Tools/workspace_AVR/COTS/01\ -\ MCAL/01-AVR/05-ADC/ADC_program.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"ADC_program.d" -MT"ADC_program.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


