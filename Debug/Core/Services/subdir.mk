################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Services/flight_core.c 

C_DEPS += \
./Core/Services/flight_core.d 

OBJS += \
./Core/Services/flight_core.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Services/%.o Core/Services/%.su Core/Services/%.cyclo: ../Core/Services/%.c Core/Services/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/home/min/Min_Drone/stm32f411_fc_fw/Core/Modules" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"/home/min/Min_Drone/stm32f411_fc_fw/Core/Services" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Services

clean-Core-2f-Services:
	-$(RM) ./Core/Services/flight_core.cyclo ./Core/Services/flight_core.d ./Core/Services/flight_core.o ./Core/Services/flight_core.su

.PHONY: clean-Core-2f-Services

