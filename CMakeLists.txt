cmake_minimum_required(VERSION 3.16)

project(hw_c_plus_plus)
set(CMAKE_CXX_STANDARD 17)

SET(GCC_COVERAGE_COMPILE_FLAGS "--coverage")
add_compile_options("--coverage")
add_link_options("--coverage")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

ENABLE_TESTING()

add_subdirectory(project)
add_subdirectory(tests)

