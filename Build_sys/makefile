################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

ifneq ($(MAKECMDGOALS),clean)
#ifneq ($(strip $(S_DEPS)),)
#-include $(S_DEPS)
#endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
#ifneq ($(strip $(C_DEPS)),)
#-include $(C_DEPS)
#endif
endif

-include ../makefile.defs

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

# Source files
C_SRCS += \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Startup/startup_stm32f407vgtx.s 

C_DEPS += \
./Out_built/Obj/main.d \
./Out_built/Obj/syscalls.d \
./Out_built/Obj/sysmem.d

S_DEPS += \
./Out_built/Obj/startup_stm32f407vgtx.d 

# Object files
OBJS += \
./Out_built/Obj/main.o \
./Out_built/Obj/syscalls.o \
./Out_built/Obj/sysmem.o \
./Out_built/Obj/startup_stm32f407vgtx.o

#Include files
CMSIS_LIBS= -I"C:/Users/p.tapiarojas/STM32CubeIDE/workspace_1.17.0/STM32F4_ARM_BMDEV/cmsis_lib"
DEVICE_LIBS= -I"C:/Users/p.tapiarojas/STM32CubeIDE/workspace_1.17.0/STM32F4_ARM_BMDEV/stm32f4_device_libs"

# All Target
all: main-build

# Main-build Target
main-build: $(EXECUTABLES) secondary-outputs

# Tool invocations
ARMF4_Bm_Dev.elf ARMF4_Bm_Dev.map: $(OBJS) C:\Users\p.tapiarojas\STM32CubeIDE\workspace_1.17.0\STM32F4_ARM_BMDEV\STM32F407VGTX_FLASH.ld makefile objects.list 
	arm-none-eabi-gcc -o "ARMF4_Bm_Dev.elf" @"objects.list" -mcpu=cortex-m4 -T"C:\Users\p.tapiarojas\STM32CubeIDE\workspace_1.17.0\STM32F4_ARM_BMDEV\STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="ARMF4_Bm_Dev.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo ' ------ .ELF and .Map Files building ...: $@ ------'
	@echo ' '

./Out_built/Obj/%.o ./Out_built/Obj/%.su ./Out_built/Obj/%.cyclo: ../Src/%.c 
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407xx -c $(CMSIS_LIBS) $(DEVICE_LIBS) -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
	@echo ' ------ .Obj from SRC files building...: $@ ------'
	@echo ' '

./Out_built/Obj/%.o: ../Startup/%.s
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
	@echo ' '
	@echo '------ Obj from Code Startup files building: $@ ------'
	@echo ' '

ARMF4_Bm_Dev.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy -O binary "ARMF4_Bm_Dev.elf" "ARMF4_Bm_Dev.bin"
	@echo ' '
	@echo '------ Binary file building: $@ ------'
	@echo ' '

ARMF4_Bm_Dev.list: $(EXECUTABLES) makefile objects.list
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "ARMF4_Bm_Dev.list"
	@echo ' '
	@echo '------ Building Memory list: $@ ------'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list
	arm-none-eabi-size  $(EXECUTABLES)
	@echo ' '
	@echo '------ Building STDOUT Size finished: $@ ------'
	@echo ' '

# Flash Target
flash: ARMF4_Bm_Dev.bin
	STM32_Programmer_CLI -c port=SWD -d ARMF4_Bm_Dev.bin 0x08000000 -rst
	@echo '------ Flash MCU finishing: $@ ------'

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(BIN_FILES) 

# Other Targets
clean:
	-$(RM) ./flash/*.elf ./flash/*.map
	-$(RM) ./Startup/startup_stm32f407vgtx.d ./Startup/startup_stm32f407vgtx.o
	-$(RM) ./Out_built/Obj/*.cyclo ./Out_built/Obj/*.d ./Out_built/Obj/*.list ./Out_built/Obj/*.o ./Out_built/Obj/*.su 
	@echo ' '
	@echo '------ Generated files removed: $@ ------'
	@echo ' '

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets