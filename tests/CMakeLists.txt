cmake_minimum_required(VERSION 3.16)

set(PROJECT_SOURCE_FILES
        ../project/src/memory.c
        ../project/src/parse_user_email.c)

add_executable(tests test.cpp ${PROJECT_SOURCE_FILES})

include_directories(../project/include)

target_link_libraries(tests ${GTEST_LIBRARIES} pthread)
