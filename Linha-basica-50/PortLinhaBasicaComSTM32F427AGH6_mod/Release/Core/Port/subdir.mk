################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Port/DisplayCM.c \
../Core/Port/NetConfig.c \
../Core/Port/Sistema.c \
../Core/Port/adc.c \
../Core/Port/battram.c \
../Core/Port/calculos.c \
../Core/Port/calculos1.c \
../Core/Port/calculosCM.c \
../Core/Port/display.c \
../Core/Port/extint.c \
../Core/Port/flash.c \
../Core/Port/global.c \
../Core/Port/interface.c \
../Core/Port/interfaceCM.c \
../Core/Port/linhabasica_port.c \
../Core/Port/modbus.c \
../Core/Port/principal.c \
../Core/Port/rtc.c \
../Core/Port/timer.c \
../Core/Port/uart.c \
../Core/Port/wdt.c 

OBJS += \
./Core/Port/DisplayCM.o \
./Core/Port/NetConfig.o \
./Core/Port/Sistema.o \
./Core/Port/adc.o \
./Core/Port/battram.o \
./Core/Port/calculos.o \
./Core/Port/calculos1.o \
./Core/Port/calculosCM.o \
./Core/Port/display.o \
./Core/Port/extint.o \
./Core/Port/flash.o \
./Core/Port/global.o \
./Core/Port/interface.o \
./Core/Port/interfaceCM.o \
./Core/Port/linhabasica_port.o \
./Core/Port/modbus.o \
./Core/Port/principal.o \
./Core/Port/rtc.o \
./Core/Port/timer.o \
./Core/Port/uart.o \
./Core/Port/wdt.o 

C_DEPS += \
./Core/Port/DisplayCM.d \
./Core/Port/NetConfig.d \
./Core/Port/Sistema.d \
./Core/Port/adc.d \
./Core/Port/battram.d \
./Core/Port/calculos.d \
./Core/Port/calculos1.d \
./Core/Port/calculosCM.d \
./Core/Port/display.d \
./Core/Port/extint.d \
./Core/Port/flash.d \
./Core/Port/global.d \
./Core/Port/interface.d \
./Core/Port/interfaceCM.d \
./Core/Port/linhabasica_port.d \
./Core/Port/modbus.d \
./Core/Port/principal.d \
./Core/Port/rtc.d \
./Core/Port/timer.d \
./Core/Port/uart.d \
./Core/Port/wdt.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Port/%.o: ../Core/Port/%.c Core/Port/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F427xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../LWIP/App -I../LWIP/Target -I../Middlewares/Third_Party/LwIP/src/include -I../Middlewares/Third_Party/LwIP/system -I../Middlewares/Third_Party/LwIP/src/include/netif/ppp -I../Middlewares/Third_Party/LwIP/src/include/lwip -I../Middlewares/Third_Party/LwIP/src/include/lwip/apps -I../Middlewares/Third_Party/LwIP/src/include/lwip/priv -I../Middlewares/Third_Party/LwIP/src/include/lwip/prot -I../Middlewares/Third_Party/LwIP/src/include/netif -I../Middlewares/Third_Party/LwIP/src/include/compat/posix -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/arpa -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/net -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/sys -I../Middlewares/Third_Party/LwIP/src/include/compat/stdc -I../Middlewares/Third_Party/LwIP/system/arch -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Port

clean-Core-2f-Port:
	-$(RM) ./Core/Port/DisplayCM.d ./Core/Port/DisplayCM.o ./Core/Port/NetConfig.d ./Core/Port/NetConfig.o ./Core/Port/Sistema.d ./Core/Port/Sistema.o ./Core/Port/adc.d ./Core/Port/adc.o ./Core/Port/battram.d ./Core/Port/battram.o ./Core/Port/calculos.d ./Core/Port/calculos.o ./Core/Port/calculos1.d ./Core/Port/calculos1.o ./Core/Port/calculosCM.d ./Core/Port/calculosCM.o ./Core/Port/display.d ./Core/Port/display.o ./Core/Port/extint.d ./Core/Port/extint.o ./Core/Port/flash.d ./Core/Port/flash.o ./Core/Port/global.d ./Core/Port/global.o ./Core/Port/interface.d ./Core/Port/interface.o ./Core/Port/interfaceCM.d ./Core/Port/interfaceCM.o ./Core/Port/linhabasica_port.d ./Core/Port/linhabasica_port.o ./Core/Port/modbus.d ./Core/Port/modbus.o ./Core/Port/principal.d ./Core/Port/principal.o ./Core/Port/rtc.d ./Core/Port/rtc.o ./Core/Port/timer.d ./Core/Port/timer.o ./Core/Port/uart.d ./Core/Port/uart.o ./Core/Port/wdt.d ./Core/Port/wdt.o

.PHONY: clean-Core-2f-Port

