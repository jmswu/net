cmake_minimum_required(VERSION 3.22)
project(net_test)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS On)

set (GCC_CXX_COVERAGE_COMPILE_FLAGS "-Werror -Wall -Wextra -Weffc++ -fno-rtti -fno-exceptions -Wpointer-arith -Wcast-align -Wwrite-strings -Wswitch-default -Wunreachable-code -Winit-self -Wmissing-field-initializers -Wno-unknown-pragmas -Wundef -Wno-misleading-indentation")
set (CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} ${GCC_CXX_COVERAGE_COMPILE_FLAGS})

add_executable(${CMAKE_PROJECT_NAME}
    main.cpp
)