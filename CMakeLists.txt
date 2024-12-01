cmake_minimum_required(VERSION 3.5)
project(advent-of-code-2024)

set(CMAKE_CXX_STANDARD 23 CACHE STRING "")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Target
if (NOT DEFINED TARGET_PROBLEM)
    message(FATAL_ERROR "TARGET_PROBLEM not found")
endif()
message("with TARGET_PROBLEM=${TARGET_PROBLEM}")
set (TARGET_PART1 ${TARGET_PROBLEM}/part1.cpp)
set (TARGET_PART2 ${TARGET_PROBLEM}/part2.cpp)
set (TARGET_INPUT ${TARGET_PROBLEM}/input)

file(COPY ${TARGET_INPUT} DESTINATION ${CMAKE_BINARY_DIR})
message("Copying ${TARGET_INPUT} to ${CMAKE_BINARY_DIR}")

add_executable(solution_part1 ${TARGET_PART1})
add_executable(solution_part2 ${TARGET_PART2})

