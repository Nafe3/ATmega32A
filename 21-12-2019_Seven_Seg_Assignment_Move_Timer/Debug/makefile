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
21-12-2019_Seven_Seg_Assignment_Move_Timer.lss \

FLASH_IMAGE += \
21-12-2019_Seven_Seg_Assignment_Move_Timer.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: 21-12-2019_Seven_Seg_Assignment_Move_Timer.elf secondary-outputs

# Tool invocations
21-12-2019_Seven_Seg_Assignment_Move_Timer.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,21-12-2019_Seven_Seg_Assignment_Move_Timer.map -mmcu=atmega32 -o "21-12-2019_Seven_Seg_Assignment_Move_Timer.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

21-12-2019_Seven_Seg_Assignment_Move_Timer.lss: 21-12-2019_Seven_Seg_Assignment_Move_Timer.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 21-12-2019_Seven_Seg_Assignment_Move_Timer.elf  >"21-12-2019_Seven_Seg_Assignment_Move_Timer.lss"
	@echo 'Finished building: $@'
	@echo ' '

21-12-2019_Seven_Seg_Assignment_Move_Timer.hex: 21-12-2019_Seven_Seg_Assignment_Move_Timer.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 21-12-2019_Seven_Seg_Assignment_Move_Timer.elf  "21-12-2019_Seven_Seg_Assignment_Move_Timer.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 21-12-2019_Seven_Seg_Assignment_Move_Timer.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 21-12-2019_Seven_Seg_Assignment_Move_Timer.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 21-12-2019_Seven_Seg_Assignment_Move_Timer.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
