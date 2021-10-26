cmake_minimum_required(VERSION 3.21.3)

set(CMAKE_GENERATOR "Ninja")


set(CMAKE_C_COMPILER "C:/Program Files (x86)/GNU Arm Embedded Toolchain/10 2021.07/bin/arm-none-eabi-gcc.exe")
set(CMAKE_CXX_COMPILER "C:/Program Files (x86)/GNU Arm Embedded Toolchain/10 2021.07/bin/arm-none-eabi-gcc.exe")
set(CMAKE_SYSTEM_PROCESSOR ARM)

project(guitar_pedal)

set(EXECUTABLE ${PROJECT_NAME}.elf)
set(LINKER_FILE ${CMAKE_SOURCE_DIR}/blink.lds)

enable_language(C ASM)

set(SRC_FILES 
    src/main.c
    src/usart.c
    src/util.c
    )

target_include_directories(${EXECUTABLE} PRIVATE
                          src
                          include
                          )

add_executable(${EXECUTABLE} ${SRC_FILES})

target_compile_options(${EXECUTABLE} PRIVATE
                       -mcpu=cortex-m0
                       -mthumb
                       -fdata-sections
                       -ffunction-sections
                       -Wall
                       -O0
                      )

target_link_options(${EXECUTABLE} PRIVATE
                    -T${LINKER_FILE}
                    -mcpdu=cortex-m0
                    -mthumb
                    )