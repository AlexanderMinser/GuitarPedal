cmake_minimum_required(VERSION 3.21.3)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_GENERATOR "Ninja" CACHE INTERNAL "" FORCE)
message("cmake gen ${CMAKE_GENERATOR}")

set(CMAKE_TOOLCHAIN_FILE "C:/projects/PersonalProjects/guitar_pedal/arm-gcc-toolchain.cmake")

project(guitar_pedal)

set(EXECUTABLE ${PROJECT_NAME}.elf)
set(LINKER_FILE ${CMAKE_SOURCE_DIR}/src/config/l152/pedal_l152.lds)

enable_language(C ASM)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(SRC_FILES
    src/config/l152/boot_l152.S
    src/usart.c
    src/util.c
    #src/interrupts.c
    src/gpio.c
    src/rcc.c
    src/main.c
    )

add_executable(${EXECUTABLE} ${SRC_FILES})

target_include_directories(${EXECUTABLE} PRIVATE
                          src
                          include
                          include/config
                          include/config/l152
                          )

target_compile_options(${EXECUTABLE} PRIVATE
                       -mcpu=cortex-m0
                       -mthumb
                       -fdata-sections
                       -ffunction-sections
                       -Wall
                       -Werror
                       -O0
                       -g3
                      )

target_link_options(${EXECUTABLE} PRIVATE
                    -T${LINKER_FILE}
                    -mcpu=cortex-m0
                    -mthumb
                    -lc
                    -lm
                    -Wall
                    -Werror
                    -Xlinker
                    -Map=${PROJECT_NAME}.map
                    )