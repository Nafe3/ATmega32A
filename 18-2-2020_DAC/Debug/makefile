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
18-2-2020_DAC.lss \

FLASH_IMAGE += \
18-2-2020_DAC.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: 18-2-2020_DAC.elf secondary-outputs

# Tool invocations
18-2-2020_DAC.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,18-2-2020_DAC.map -mmcu=atmega32 -o "18-2-2020_DAC.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

18-2-2020_DAC.lss: 18-2-2020_DAC.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 18-2-2020_DAC.elf  >"18-2-2020_DAC.lss"
	@echo 'Finished building: $@'
	@echo ' '

18-2-2020_DAC.hex: 18-2-2020_DAC.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 18-2-2020_DAC.elf  "18-2-2020_DAC.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 18-2-2020_DAC.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 18-2-2020_DAC.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: 18-2-2020_DAC.elf
	@echo 'Invoking: AVRDude'
	D:\ITI\Subjects\Intro to ES-Assaf\Tools\SDK\IMT_SDK_Win_64_AVR\WinAVR\bin\avrdude -pm32 -cusbasp -Uflash:w:18-2-2020_DAC.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 18-2-2020_DAC.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
