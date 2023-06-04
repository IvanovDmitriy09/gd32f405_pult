################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/ILI9341_GFX.c \
../Src/fonts.c \
../Src/main.c \
../Src/timer.c \
../Src/write.c \
../Src/xpt2046_touch.c 

OBJS += \
./Src/ILI9341_GFX.o \
./Src/fonts.o \
./Src/main.o \
./Src/timer.o \
./Src/write.o \
./Src/xpt2046_touch.o 

C_DEPS += \
./Src/ILI9341_GFX.d \
./Src/fonts.d \
./Src/main.d \
./Src/timer.d \
./Src/write.d \
./Src/xpt2046_touch.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c Src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra -g3 -DDEBUG -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -I"../Inc" -I"../System/Inc" -I"../System/Inc/CMSIS" -I"../System/Inc/gd32f4xx" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


