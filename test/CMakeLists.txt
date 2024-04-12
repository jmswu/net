cmake_minimum_required(VERSION 3.22)
project(test)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.14.0  
)
FetchContent_MakeAvailable(googletest)

# Define your test executable that incorporates your test files
add_executable(${CMAKE_PROJECT_NAME}
    test_dummy.cpp
)

# Link Google Test's main entry point to your test executable
target_link_libraries(test gtest_main gtest)