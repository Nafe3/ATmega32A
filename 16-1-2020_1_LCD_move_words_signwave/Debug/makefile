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
16-1-2020_1_LCD_move_words_signwave.lss \

FLASH_IMAGE += \
16-1-2020_1_LCD_move_words_signwave.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: 16-1-2020_1_LCD_move_words_signwave.elf secondary-outputs

# Tool invocations
16-1-2020_1_LCD_move_words_signwave.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,16-1-2020_1_LCD_move_words_signwave.map -mmcu=atmega32 -o "16-1-2020_1_LCD_move_words_signwave.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

16-1-2020_1_LCD_move_words_signwave.lss: 16-1-2020_1_LCD_move_words_signwave.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 16-1-2020_1_LCD_move_words_signwave.elf  >"16-1-2020_1_LCD_move_words_signwave.lss"
	@echo 'Finished building: $@'
	@echo ' '

16-1-2020_1_LCD_move_words_signwave.hex: 16-1-2020_1_LCD_move_words_signwave.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 16-1-2020_1_LCD_move_words_signwave.elf  "16-1-2020_1_LCD_move_words_signwave.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 16-1-2020_1_LCD_move_words_signwave.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 16-1-2020_1_LCD_move_words_signwave.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: 16-1-2020_1_LCD_move_words_signwave.elf
	@echo 'Invoking: AVRDude'
	D:\ITI\Subjects\Intro to ES-Assaf\Tools\SDK\IMT_SDK_Win_64_AVR\WinAVR\bin\avrdude -pm32 -cusbasp -u -Uflash:w:16-1-2020_1_LCD_move_words_signwave.hex:a -Ulfuse:w:0xff:m -Uhfuse:w:0x99:m
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 16-1-2020_1_LCD_move_words_signwave.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
