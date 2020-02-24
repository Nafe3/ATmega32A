################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
21-1-2020_Interrupt.lss \

FLASH_IMAGE += \
21-1-2020_Interrupt.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: 21-1-2020_Interrupt.elf secondary-outputs

# Tool invocations
21-1-2020_Interrupt.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,21-1-2020_Interrupt.map -mmcu=atmega32 -o "21-1-2020_Interrupt.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

21-1-2020_Interrupt.lss: 21-1-2020_Interrupt.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 21-1-2020_Interrupt.elf  >"21-1-2020_Interrupt.lss"
	@echo 'Finished building: $@'
	@echo ' '

21-1-2020_Interrupt.hex: 21-1-2020_Interrupt.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 21-1-2020_Interrupt.elf  "21-1-2020_Interrupt.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 21-1-2020_Interrupt.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 21-1-2020_Interrupt.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: 21-1-2020_Interrupt.elf
	@echo 'Invoking: AVRDude'
	D:\ITI\Subjects\Intro to ES-Assaf\Tools\SDK\IMT_SDK_Win_64_AVR\WinAVR\bin\avrdude -pm32 -cusbasp -u -Uflash:w:21-1-2020_Interrupt.hex:a -Ulfuse:w:0xff:m -Uhfuse:w:0xd9:m
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 21-1-2020_Interrupt.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
