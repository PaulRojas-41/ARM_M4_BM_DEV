################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
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

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := ARMF4_Bm_Dev
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
ARMF4_Bm_Dev.elf \

MAP_FILES += \
ARMF4_Bm_Dev.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
ARMF4_Bm_Dev.list \

BIN_FILES += \
ARMF4_Bm_Dev.bin

# All Target
all: main-build

# Main-build Target
main-build: ARMF4_Bm_Dev.elf secondary-outputs

# Tool invocations
ARMF4_Bm_Dev.elf ARMF4_Bm_Dev.map: $(OBJS) $(USER_OBJS) C:\Users\p.tapiarojas\STM32CubeIDE\workspace_1.17.0\ARMF4_Bm_Dev\STM32F407VGTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "ARMF4_Bm_Dev.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\p.tapiarojas\STM32CubeIDE\workspace_1.17.0\ARMF4_Bm_Dev\STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="ARMF4_Bm_Dev.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo *******

ARMF4_Bm_Dev.bin: ARMF4_Bm_Dev.elf
	arm-none-eabi-objcopy -O binary "ARMF4_Bm_Dev.elf" "ARMF4_Bm_Dev.bin"
	@echo 'Finished building binary: $@'
	@echo *******

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo *******

ARMF4_Bm_Dev.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "ARMF4_Bm_Dev.list"
	@echo 'Finished building: $@'
	@echo *******

# Flash Target
flash: ARMF4_Bm_Dev.bin
	STM32_Programmer_CLI -c port=SWD -d ARMF4_Bm_Dev.bin 0x08000000 -rst
	@echo 'Finished flashing: $@'
	@echo *******

# Other Targets
clean:
	-$(RM) ARMF4_Bm_Dev.elf ARMF4_Bm_Dev.list ARMF4_Bm_Dev.map default.size.stdout
	@echo ********

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(BIN_FILES)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets