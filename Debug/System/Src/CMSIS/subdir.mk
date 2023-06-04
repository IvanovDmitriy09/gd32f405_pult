################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../System/Src/CMSIS/system_gd32f4xx.c \
../System/Src/CMSIS/vectors_gd32f4xx.c 

OBJS += \
./System/Src/CMSIS/system_gd32f4xx.o \
./System/Src/CMSIS/vectors_gd32f4xx.o 

C_DEPS += \
./System/Src/CMSIS/system_gd32f4xx.d \
./System/Src/CMSIS/vectors_gd32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
System/Src/CMSIS/%.o: ../System/Src/CMSIS/%.c System/Src/CMSIS/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra -g3 -DDEBUG -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -I"../Inc" -I"../System/Inc" -I"../System/Inc/CMSIS" -I"../System/Inc/gd32f4xx" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


