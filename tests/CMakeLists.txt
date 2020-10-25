cmake_minimum_required(VERSION 3.16)

#set(PROJECT_SOURCE_FILES)

add_executable(tests test.cpp ${PROJECT_SOURCE_FILES})

include_directories(../include)
include_directories(../lib/parallel)
include_directories(../lib/sequential)

target_link_libraries(tests ${GTEST_LIBRARIES} pthread)
target_link_libraries(tests sequential_lib parallel_lib)
