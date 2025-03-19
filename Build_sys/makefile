################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf 

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
../Drv_ll_dev/GPIO_LED/main.c \
../Drv_ll_dev/Startup_code/syscalls.c \
../Drv_ll_dev/Startup_code/sysmem.c \
../Startup/startup_stm32f407vgtx.s 

C_DEPS += \
./Out_built/Obj/main.d \
./Out_built/Obj/syscalls.d \
./Out_built/Obj/sysmem.d

S_DEPS += \
./Out_built/Obj/startup_stm32f407vgtx.d 

# Object files
OBJS += \
./Out_built/Obj/Drv_ll_adc.o \
./Out_built/Obj/DrV_ll_gpioLed.o \
./Out_built/Obj/syscalls.o \
./Out_built/Obj/sysmem.o \
./Out_built/Obj/startup_stm32f407vgtx.o

#Include files
CMSIS_LIBS= -I"C:/Users/p.tapiarojas/STM32CubeIDE/workspace_1.17.0/STM32F4_ARM_BMDEV/cmsis_lib"
DEVICE_LIBS= -I"C:/Users/p.tapiarojas/STM32CubeIDE/workspace_1.17.0/STM32F4_ARM_BMDEV/stm32f4_device_libs"

#Linker files 
LINKER_FLASH_DIR := C:/Users/p.tapiarojas/STM32CubeIDE/workspace_1.17.0/STM32F4_ARM_BMDEV/Build_sys/Linker/STM32F407VGTX_FLASH.ld
LINKER_SCRIPT := -T./Linker/STM32F407VGTX_FLASH.ld

# All Target
all: main-build

# Main-build Target
main-build: $(EXECUTABLES) secondary-outputs

#line 69: build all the objects 
ARMF4_Bm_Dev.elf ARMF4_Bm_Dev.map: $(OBJS) $(LINKER_FLASH_DIR) makefile objects.list 
	arm-none-eabi-gcc -o "ARMF4_Bm_Dev.elf" @"objects.list" -mcpu=cortex-m4 $(LINKER_SCRIPT) --specs=nosys.specs -Wl,-Map="ARMF4_Bm_Dev.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo ' ------ .ELF and .Map Files building ...: $@ ------'
	@echo ' '

#./Out_built/Obj/%.o: ../Drv_ll_dev/Startup_code/%.c 
#	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407xx -c $(CMSIS_LIBS) $(DEVICE_LIBS) -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
#	@echo ' [Build] Startup code .Obj files : ../Drv_ll_dev/Startup_code/ '
#	@echo ' '
#
#./Out_built/Obj/%.o: ../Drv_ll_dev/%.c 
#	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407xx -c $(CMSIS_LIBS) $(DEVICE_LIBS) -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
#	@echo ' [Build] Drv Low Layer .Obj files : ../Drv_ll_dev/ '
#	@echo ' '
#
#./Out_built/Obj/%.o: ../Startup/%.s
#	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
#	@echo ' '
#	@echo '------ Obj from Code Startup files building: $@ ------'
#	@echo ' '

###### Objects to build ADC target rule ######
ADC_OBJS += \
./Out_built/Obj_adc/Drv_ll_adc.o \
./Out_built/Obj_sys/syscalls.o \
./Out_built/Obj_sys/sysmem.o \
./Out_built/Obj_startup/startup_stm32f407vgtx.o

###### Objects to clean ADC built targets ######
DRV_OBJ_DIR_CL = $(wildcard ./Out_built/Obj_*)



######## BUILD ALL Strategy ########


#PLACEHOLDER FOR ADC BUILD STRATEGY

######## BUILD ALL Strategy ########

####### BUILD ADC strategy ########

./Out_built/Obj_adc/%.o: ../Drv_ll_dev/ADC/%.c
	@mkdir -p $(@D)
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407xx -c $(CMSIS_LIBS) $(DEVICE_LIBS) -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
	@echo ' '
	@echo ' [Building...] Drv_Adc .Obj file : [Obj files from SRC...]' 
	@echo ' '

./Out_built/Obj_sys/%.o: ../Drv_ll_dev/Sys_startup_Code/%.c
	@mkdir -p $(@D)
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407xx -c $(CMSIS_LIBS) $(DEVICE_LIBS) -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
	@echo ' '
	@echo ' [Building...] Startup_Code .Obj file : [Obj files from SRC...]'
	@echo ' '

./Out_built/Obj_startup/%.o: ../Startup/%.s
	@mkdir -p $(@D)
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
	@echo ' '
	@echo ' [Building...] Startup Code : [Obj files from ASM code...]'
	@echo ' '

drv_adc: $(ADC_OBJS) $(LINKER_FLASH_DIR) 
	arm-none-eabi-gcc -o "drv_adc.elf" $(ADC_OBJS) -mcpu=cortex-m4 $(LINKER_SCRIPT) --specs=nosys.specs -Wl,-Map="drv_adc.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo ' '
	@echo ' [Linking...] Drv_Adc .Obj file : $@' 
	@echo ' [Linking...] Startup_Code .Obj file'
	@echo ' '

####### BUILD ADC strategy ########

####### this action is not called, because .bin has not been generated ######

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

#Clean target 
clean:
	@echo ' '
	@echo '[Cleaning Target Files...]'
	@echo ' '

	-$(RM) *.elf *.map *bin ARMF4_Bm_Dev.list
	-$(RM) $(DRV_OBJ_DIR_CL)
	@echo ' '
	@echo '[Cleaning Finished...]'
	@echo ' '

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets