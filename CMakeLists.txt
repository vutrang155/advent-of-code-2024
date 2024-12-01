cmake_minimum_required(VERSION 3.5)
project(advent-of-code-2024)

set(CMAKE_CXX_STANDARD 23 CACHE STRING "")

# Target
if (NOT DEFINED TARGET_PROBLEM)
    message(FATAL_ERROR "TARGET_PROBLEM not found")
endif()
message("with TARGET_PROBLEM=${TARGET_PROBLEM}")
set (TARGET_SOURCE ${TARGET_PROBLEM}/solution.cpp)
set (TARGET_INPUT ${TARGET_PROBLEM}/input)

file(COPY ${TARGET_INPUT} DESTINATION ${CMAKE_BINARY_DIR})
message("Copying ${TARGET_INPUT} to ${CMAKE_BINARY_DIR}")

add_executable(solution ${TARGET_SOURCE})
