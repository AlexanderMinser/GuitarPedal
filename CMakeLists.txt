cmake_minimum_required(VERSION 3.21.3)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_GENERATOR "Ninja")

set(CMAKE_TOOLCHAIN_FILE "C:/projects/PersonalProjects/guitar_pedal/arm-gcc-toolchain.cmake")

project(guitar_pedal)

set(EXECUTABLE ${PROJECT_NAME}.elf)
set(LINKER_FILE ${CMAKE_SOURCE_DIR}/blink.lds)

enable_language(C ASM)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(SRC_FILES
    src/boot.S
    src/main.c
    src/usart.c
    src/util.c
    )

add_executable(${EXECUTABLE} ${SRC_FILES})

target_include_directories(${EXECUTABLE} PRIVATE
                          src
                          include
                          )

target_compile_options(${EXECUTABLE} PRIVATE
                       -mcpu=cortex-m0
                       -mthumb
                       -fdata-sections
                       -ffunction-sections
                       -Wall
                       -O0
                       -v
                      )

target_link_options(${EXECUTABLE} PRIVATE
                    -T${LINKER_FILE}
                    -mcpu=cortex-m0
                    -mthumb
                    -lc
                    -lm
                    -Wl,--gc-sections
                    -Xlinker
                    -Map=${PROJECT_NAME}.map
                    -v
                    )

set_target_properties(${EXECUTABLE} PROPERTIES LINK_DEPENDS ${LINKER_FILE})