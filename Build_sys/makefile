################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

-include ../makefile.init 
-include ../makefile.targets 

RM := rm -rf 

BUILD_ARTIFACT_NAME := drv_adc
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
$(BUILD_ARTIFACT_NAME).elf \

MAP_FILES += \
$(BUILD_ARTIFACT_NAME).map \

OBJDUMP_LIST += \
$(BUILD_ARTIFACT_NAME).list \

BIN_FILES += \
$(BUILD_ARTIFACT_NAME).bin

SIZE_OUTPUT += \
default.size.stdout \

######## build driver section ########

#CMSIS libraries 
CMSIS_LIBS= -I"C:/Users/p.tapiarojas/STM32CubeIDE/workspace_1.17.0/STM32F4_ARM_BMDEV/cmsis_lib"
DEVICE_LIBS= -I"C:/Users/p.tapiarojas/STM32CubeIDE/workspace_1.17.0/STM32F4_ARM_BMDEV/stm32f4_device_libs"

#Linker files 
LINKER_FLASH_DIR := C:/Users/p.tapiarojas/STM32CubeIDE/workspace_1.17.0/STM32F4_ARM_BMDEV/Build_sys/Linker/STM32F407VGTX_FLASH.ld
LINKER_SCRIPT := -T"./Linker/STM32F407VGTX_FLASH.ld"

# Make vars for directories 
OUT_BUILT_DIR := ./Out_built
DRV_DIR := ../Dev/all_drv/$(BUILD_ARTIFACT_NAME)
ALL_DRV_DIR := ../Dev/all_drv
ASM_DIR := ../Startup

# Make vars for files to build 
DRV_FILE = $(wildcard $(DRV_DIR)/*)
ALL_DRV_FILES = $(wildcard $(ALL_DRV_DIR)/**/*)
ASM_FILE = $(wildcard $(ASM_DIR)/*)
SYS_FILES = $(wildcard ../Dev/sys_code/*)

BUILD_OBJ_DRVS += $(patsubst %.c, ./Out_built/obj_drv/%.o, $(notdir $(ALL_DRV_FILES)))
BUILD_OBJ_SYS  += $(patsubst %.c, ./Out_built/obj_sys/%.o, $(notdir $(SYS_FILES)))
BUILD_OBJ_ASM  += $(patsubst %.s, ./Out_built/obj_asm/%.o, $(notdir $(ASM_FILE)))

# List of objects to build for a single driver
BUILD_OBJ += \
	$(OUT_BUILT_DIR)/obj_drv/$(BUILD_ARTIFACT_NAME).o \
	$(BUILD_OBJ_ASM) \
	$(BUILD_OBJ_SYS)

ALL_OBJS += \
	$(BUILD_OBJ_DRVS) \
	$(BUILD_OBJ_SYS) \
	$(BUILD_OBJ_ASM)

driver: $(BUILD_ARTIFACT_NAME) binary-build

$(BUILD_ARTIFACT_NAME): $(BUILD_OBJ) $(LINKER_FLASH_DIR)
	arm-none-eabi-gcc -o "$@".elf $(BUILD_OBJ) -mcpu=cortex-m4 $(LINKER_SCRIPT) --specs=nosys.specs -Wl,-Map="$@".map -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group 
	@echo ' '
	@echo ' [Linking...] '
	@echo ' '
	@echo ' [Finished building driver ...] '
	@echo ' '

$(OUT_BUILT_DIR)/obj_drv/%.o: $(DRV_FILE) 
	@mkdir -p $(@D)
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407xx -c $(CMSIS_LIBS) $(DEVICE_LIBS) -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
	@echo ' '
	@echo ' [Building Driver application ...]'
	@echo ' '

$(OUT_BUILT_DIR)/obj_sys/%.o: ../Dev/sys_code/%.c
	@mkdir -p $(@D)
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407xx -c $(CMSIS_LIBS) $(DEVICE_LIBS) -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
	@echo ' '
	@echo ' [Building system code ...]'
	@echo ' '

$(OUT_BUILT_DIR)/obj_asm/%.o: $(ASM_FILE)
	@mkdir -p $(@D)
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
	@echo ' '
	@echo '[Assembling ...]'
	@echo ' '

binary-build: $(BIN_FILES) $(OBJDUMP_LIST) $(SIZE_OUTPUT) 
	@echo ' '
	@echo '[Building binary files ...]'
	@echo ' '

$(BIN_FILES): $(BUILD_ARTIFACT)
	arm-none-eabi-objcopy -O binary $(BUILD_ARTIFACT) $(BUILD_ARTIFACT_NAME).bin
	@echo ' '
	@echo '[Building binary file...]'
	@echo ' '

$(OBJDUMP_LIST): $(BUILD_ARTIFACT) $(BUILD_OBJS)
	arm-none-eabi-objdump -h -S $(BUILD_ARTIFACT) > "$@"
	@echo ' '
	@echo '[Building memory application list...]'
	@echo ' '

$(SIZE_OUTPUT): $(EXECUTABLES) $(BUILD_OBJS) 
	arm-none-eabi-size  $(EXECUTABLES)
	@echo ' '
	@echo '[Building application driver size output....]'
	@echo ' '

flash: $(BIN_FILES)
	STM32_Programmer_CLI -c port=SWD -d "$<" 0x08000000 -rst
	@echo ' '
	@echo '[Flashing driver application into MCU....]'
	@echo ' '

clean:
	-$(RM) @echo '[Cleaning ELF and MAP...]' *.elf *.map *bin *.list
	-$(RM) @echo '[Cleaning Out Built dirs...]' $(OUT_BUILT_DIR) 
	@echo ' '

################# TEST SECTION  #################

test2:
	@echo '[DRV_FILES expansion.......] $(ALL_DRV_FILES)'

################# TEST SECTION END #################

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets