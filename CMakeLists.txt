cmake_minimum_required(VERSION 3.27)
project(smo_mods) # Rename to something that you like

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXECUTABLE_SUFFIX ".elf")

add_compile_options(--target=aarch64-none-elf)
add_compile_options(-mcpu=cortex-a57+fp+simd+crypto+crc)
add_compile_options(-mno-implicit-float)
add_compile_options(-stdlib=libc++)
add_compile_options(-fPIC)
add_compile_options(-fstandalone-debug)
add_compile_options(-v -Wall -O3 -nodefaultlibs -nostdlib -ffunction-sections -fdata-sections)
add_compile_options(-Werror=return-type)
add_compile_options(-fno-asynchronous-unwind-tables -fno-unwind-tables)
add_compile_definitions(ARDUINOJSON_ENABLE_COMMENTS SWITCH)
add_link_options(-shared -ffunction-sections -fdata-sections)
add_link_options(-stdlib=libc++ -nodefaultlibs -nostdlib)

include_directories(${PROJECT_SOURCE_DIR}/src/framework/libs/)
include_directories(${PROJECT_SOURCE_DIR}/src/framework/libs/exlaunch/)
include_directories(${PROJECT_SOURCE_DIR}/src/framework/libs/smo/al)
include_directories(${PROJECT_SOURCE_DIR}/src/framework/libs/smo/agl)
include_directories(${PROJECT_SOURCE_DIR}/src/framework/libs/smo/game)
include_directories(${PROJECT_SOURCE_DIR}/src/framework/libs/smo/NintendoSDK)
include_directories(${PROJECT_SOURCE_DIR}/src/framework/libs/smo/sead)

add_compile_definitions(NNSDK=1)

# Change this depending on the SDK version you are targeting
set(NN_SDK_MAJOR 3)
set(NN_SDK_MINOR 5)
set(NN_SDK_PATCH 1)
set(NN_SDK_TYPE "Release")

if (NOT ML_MOD_NAME)
    message(FATAL_ERROR "The variable 'ML_MOD_NAME' must be specified in your configuration")
endif ()

# Some configuration the framework expects
set(ML_TOOLS_DIR ${CMAKE_SOURCE_DIR}/src/framework/tools)
set(ML_OUTPUT_DIR ${CMAKE_SOURCE_DIR}/out/${ML_MOD_NAME})

option(ML_ENABLE_LOG "Enable Logging" ON) # Logging macros expand to nothing if this is turned off. Plain calls to mallow::log::* still compile and run

if (ML_ENABLE_LOG)
    add_compile_definitions(ML_ENABLE_LOG)
endif()

# Framework and Mods
add_subdirectory(src/framework)
add_subdirectory(src/mods)

# Deployment
include(deploy.cmake)
