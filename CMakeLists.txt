cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -fprofile-arcs -ftest-coverage -g -O0")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

project(hw_c_plus_plus)

#configure_file(CMakeLists.txt.in
#        googletest-download/CMakeLists.txt)
#execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
#        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
#execute_process(COMMAND ${CMAKE_COMMAND} --build .
#        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
#
#add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
#        ${CMAKE_BINARY_DIR}/googletest-build)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

ENABLE_TESTING()

add_subdirectory(project)
add_subdirectory(tests)

