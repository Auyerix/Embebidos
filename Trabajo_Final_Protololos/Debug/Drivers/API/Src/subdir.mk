################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/API/Src/API_debounce.c \
../Drivers/API/Src/API_delay.c \
../Drivers/API/Src/API_lcd.c \
../Drivers/API/Src/API_scheduler.c \
../Drivers/API/Src/API_screen_managment.c \
../Drivers/API/Src/API_uart.c \
../Drivers/API/Src/BMP180.c \
../Drivers/API/Src/port.c 

OBJS += \
./Drivers/API/Src/API_debounce.o \
./Drivers/API/Src/API_delay.o \
./Drivers/API/Src/API_lcd.o \
./Drivers/API/Src/API_scheduler.o \
./Drivers/API/Src/API_screen_managment.o \
./Drivers/API/Src/API_uart.o \
./Drivers/API/Src/BMP180.o \
./Drivers/API/Src/port.o 

C_DEPS += \
./Drivers/API/Src/API_debounce.d \
./Drivers/API/Src/API_delay.d \
./Drivers/API/Src/API_lcd.d \
./Drivers/API/Src/API_scheduler.d \
./Drivers/API/Src/API_screen_managment.d \
./Drivers/API/Src/API_uart.d \
./Drivers/API/Src/BMP180.d \
./Drivers/API/Src/port.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/API/Src/%.o Drivers/API/Src/%.su Drivers/API/Src/%.cyclo: ../Drivers/API/Src/%.c Drivers/API/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/home/osboxes/Gustavo/Embebidos/PdM_workspace/Trabajo_Final_Protololos/Drivers" -I"/home/osboxes/Gustavo/Embebidos/PdM_workspace/Trabajo_Final_Protololos/Drivers/API/Inc" -I"/home/osboxes/Gustavo/Embebidos/PdM_workspace/Trabajo_Final_Protololos/Drivers/API" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-API-2f-Src

clean-Drivers-2f-API-2f-Src:
	-$(RM) ./Drivers/API/Src/API_debounce.cyclo ./Drivers/API/Src/API_debounce.d ./Drivers/API/Src/API_debounce.o ./Drivers/API/Src/API_debounce.su ./Drivers/API/Src/API_delay.cyclo ./Drivers/API/Src/API_delay.d ./Drivers/API/Src/API_delay.o ./Drivers/API/Src/API_delay.su ./Drivers/API/Src/API_lcd.cyclo ./Drivers/API/Src/API_lcd.d ./Drivers/API/Src/API_lcd.o ./Drivers/API/Src/API_lcd.su ./Drivers/API/Src/API_scheduler.cyclo ./Drivers/API/Src/API_scheduler.d ./Drivers/API/Src/API_scheduler.o ./Drivers/API/Src/API_scheduler.su ./Drivers/API/Src/API_screen_managment.cyclo ./Drivers/API/Src/API_screen_managment.d ./Drivers/API/Src/API_screen_managment.o ./Drivers/API/Src/API_screen_managment.su ./Drivers/API/Src/API_uart.cyclo ./Drivers/API/Src/API_uart.d ./Drivers/API/Src/API_uart.o ./Drivers/API/Src/API_uart.su ./Drivers/API/Src/BMP180.cyclo ./Drivers/API/Src/BMP180.d ./Drivers/API/Src/BMP180.o ./Drivers/API/Src/BMP180.su ./Drivers/API/Src/port.cyclo ./Drivers/API/Src/port.d ./Drivers/API/Src/port.o ./Drivers/API/Src/port.su

.PHONY: clean-Drivers-2f-API-2f-Src

