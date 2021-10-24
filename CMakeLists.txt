cmake_minimum_required(VERSION 3.21.3)

set(CMAKE_C_COMPILER "C:/Program Files (x86)/GNU Arm Embedded Toolchain/10 2021.07/bin/arm-none-eabi-gcc.exe")
set(CMAKE_CXX_COMPILER "C:/Program Files (x86)/GNU Arm Embedded Toolchain/10 2021.07/bin/arm-none-eabi-gcc.exe")

project(Blinky)

add_executable(${PROJECT_NAME} main.c)