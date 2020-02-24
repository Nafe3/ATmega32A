################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_program.c \
../PORT_program.c \
../main.c 

OBJS += \
./DIO_program.o \
./PORT_program.o \
./main.o 

C_DEPS += \
./DIO_program.d \
./PORT_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\ITI\Subjects\Intro to ES-Assaf\Tools\SDK\IMT_SDK_Win_64_AVR\WinAVR\avr\include" -I"D:\ITI\Subjects\Intro to ES-Assaf\Tools\SDK\IMT_SDK_Win_64_AVR\WinAVR\lib\gcc\avr\4.3.3\include" -I"D:\ITI\Subjects\Intro to ES-Assaf\Tools\SDK\IMT_SDK_Win_64_AVR\WinAVR\lib\gcc\avr\4.3.3\include-fixed" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


