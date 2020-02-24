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
LED_DIP_SWITCHES.lss \

FLASH_IMAGE += \
LED_DIP_SWITCHES.hex \

EEPROM_IMAGE += \
LED_DIP_SWITCHES.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: LED_DIP_SWITCHES.elf secondary-outputs

# Tool invocations
LED_DIP_SWITCHES.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,LED_DIP_SWITCHES.map -mmcu=atmega32 -o "LED_DIP_SWITCHES.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

LED_DIP_SWITCHES.lss: LED_DIP_SWITCHES.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S LED_DIP_SWITCHES.elf  >"LED_DIP_SWITCHES.lss"
	@echo 'Finished building: $@'
	@echo ' '

LED_DIP_SWITCHES.hex: LED_DIP_SWITCHES.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex LED_DIP_SWITCHES.elf  "LED_DIP_SWITCHES.hex"
	@echo 'Finished building: $@'
	@echo ' '

LED_DIP_SWITCHES.eep: LED_DIP_SWITCHES.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex LED_DIP_SWITCHES.elf  "LED_DIP_SWITCHES.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: LED_DIP_SWITCHES.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 LED_DIP_SWITCHES.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) LED_DIP_SWITCHES.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
