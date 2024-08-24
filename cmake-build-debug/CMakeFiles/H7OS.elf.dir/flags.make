# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

# compile ASM with E:/Program Files (x86)/GNU Arm Embedded Toolchain/10 2021.10/bin/arm-none-eabi-gcc.exe
# compile C with E:/Program Files (x86)/GNU Arm Embedded Toolchain/10 2021.10/bin/arm-none-eabi-gcc.exe
ASM_DEFINES = -DARM_MATH_CM4 -DARM_MATH_MATRIX_CHECK -DARM_MATH_ROUNDING -DDEBUG -DSTM32H743xx -DUSE_HAL_DRIVER

ASM_INCLUDES = -ID:\H7OS\Core\Inc -ID:\H7OS\Drivers\STM32H7xx_HAL_Driver\Inc -ID:\H7OS\Drivers\STM32H7xx_HAL_Driver\Inc\Legacy -ID:\H7OS\Drivers\CMSIS\Device\ST\STM32H7xx\Include -ID:\H7OS\Drivers\CMSIS\Include -ID:\H7OS\FATFS\Target -ID:\H7OS\FATFS\App -ID:\H7OS\Middlewares\Third_Party\FreeRTOS\Source\include -ID:\H7OS\Middlewares\Third_Party\FreeRTOS\Source\CMSIS_RTOS -ID:\H7OS\Middlewares\Third_Party\FreeRTOS\Source\portable\GCC\ARM_CM4F -ID:\H7OS\Middlewares\Third_Party\FatFs\src -ID:\H7OS\Utilities\JPEG -ID:\H7OS\Drivers\Kernel\inc -ID:\H7OS\Applications\inc -ID:\H7OS\RAMFS

ASM_FLAGS = -g -mfloat-abi=hard -mfpu=fpv4-sp-d16 -mcpu=cortex-m7 -mthumb -mthumb-interwork -ffunction-sections -fdata-sections -fno-common -fmessage-length=0 -x assembler-with-cpp -Og -g

C_DEFINES = -DARM_MATH_CM4 -DARM_MATH_MATRIX_CHECK -DARM_MATH_ROUNDING -DDEBUG -DSTM32H743xx -DUSE_HAL_DRIVER

C_INCLUDES = -ID:\H7OS\Core\Inc -ID:\H7OS\Drivers\STM32H7xx_HAL_Driver\Inc -ID:\H7OS\Drivers\STM32H7xx_HAL_Driver\Inc\Legacy -ID:\H7OS\Drivers\CMSIS\Device\ST\STM32H7xx\Include -ID:\H7OS\Drivers\CMSIS\Include -ID:\H7OS\FATFS\Target -ID:\H7OS\FATFS\App -ID:\H7OS\Middlewares\Third_Party\FreeRTOS\Source\include -ID:\H7OS\Middlewares\Third_Party\FreeRTOS\Source\CMSIS_RTOS -ID:\H7OS\Middlewares\Third_Party\FreeRTOS\Source\portable\GCC\ARM_CM4F -ID:\H7OS\Middlewares\Third_Party\FatFs\src -ID:\H7OS\Utilities\JPEG -ID:\H7OS\Drivers\Kernel\inc -ID:\H7OS\Applications\inc -ID:\H7OS\RAMFS

C_FLAGS = -g -std=gnu11 -fdiagnostics-color=always -mfloat-abi=hard -mfpu=fpv4-sp-d16 -mcpu=cortex-m7 -mthumb -mthumb-interwork -ffunction-sections -fdata-sections -fno-common -fmessage-length=0 -Og -g
