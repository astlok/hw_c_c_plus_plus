cmake_minimum_required(VERSION 3.16)

add_executable(tests test.cpp ../project/src/parse_user_eml.c)

include_directories(../project/include)

target_link_libraries(tests ${GTEST_LIBRARIES} pthread)
