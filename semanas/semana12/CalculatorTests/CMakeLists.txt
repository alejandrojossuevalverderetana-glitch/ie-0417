cmake_minimum_required(VERSION 3.10)
project(CalculatorTests)

# Añadir Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

# Añadir el ejecutable y los tests
add_executable(test_calculator test_calculator.cpp)
target_link_libraries(test_calculator gtest_main)

enable_testing()
add_test(NAME test_calculator COMMAND test_calculator)