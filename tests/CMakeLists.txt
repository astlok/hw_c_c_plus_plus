cmake_minimum_required(VERSION 3.16)

set(PROJECT_SOURCE_FILES)

add_executable(tests test.cpp ${PROJECT_SOURCE_FILES})

include_directories(../project_consistently/include)

target_link_libraries(tests ${GTEST_LIBRARIES} pthread)
