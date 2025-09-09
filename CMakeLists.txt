cmake_minimum_required(VERSION 3.13)

# Pull in PICO SDK (copy pico_sdk_import.cmake into your project or set PICO_SDK_PATH)
include(pico_sdk_import.cmake)

project(pico_sos C CXX ASM)

# initialize the SDK
pico_sdk_init()

add_executable(pico_sos
    main.c
)

# link pico stdlib (gpio, sleep, etc.)
target_link_libraries(pico_sos pico_stdlib)

# produce uf2, hex, bin
pico_add_extra_outputs(pico_sos)
