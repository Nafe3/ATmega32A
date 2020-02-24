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
12-12-2019_delay_function_oscilloscope.lss \

FLASH_IMAGE += \
12-12-2019_delay_function_oscilloscope.hex \

EEPROM_IMAGE += \
12-12-2019_delay_function_oscilloscope.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: 12-12-2019_delay_function_oscilloscope.elf secondary-outputs

# Tool invocations
12-12-2019_delay_function_oscilloscope.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,12-12-2019_delay_function_oscilloscope.map -mmcu=atmega32 -o "12-12-2019_delay_function_oscilloscope.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

12-12-2019_delay_function_oscilloscope.lss: 12-12-2019_delay_function_oscilloscope.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 12-12-2019_delay_function_oscilloscope.elf  >"12-12-2019_delay_function_oscilloscope.lss"
	@echo 'Finished building: $@'
	@echo ' '

12-12-2019_delay_function_oscilloscope.hex: 12-12-2019_delay_function_oscilloscope.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 12-12-2019_delay_function_oscilloscope.elf  "12-12-2019_delay_function_oscilloscope.hex"
	@echo 'Finished building: $@'
	@echo ' '

12-12-2019_delay_function_oscilloscope.eep: 12-12-2019_delay_function_oscilloscope.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex 12-12-2019_delay_function_oscilloscope.elf  "12-12-2019_delay_function_oscilloscope.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 12-12-2019_delay_function_oscilloscope.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 12-12-2019_delay_function_oscilloscope.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 12-12-2019_delay_function_oscilloscope.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
