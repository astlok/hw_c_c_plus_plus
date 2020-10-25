cmake_minimum_required (VERSION 3.8)

#project(Library)

set(SOURCE_FILES_SEQ "sequential/sequential.c" "sequential/utils.c")
set(HEADER_FILES_SEQ "sequential/sequential.h" "sequential/utils.h")

set(SOURCE_FILES_PAR "parallel/parallel.c" "parallel/utils.c")
set(HEADER_FILES_PAR "parallel/parallel.h" "parallel/utils.h" "parallel/segment.h")

add_library(sequential_lib STATIC ${HEADER_FILES_SEQ} ${SOURCE_FILES_SEQ} )
add_library(parallel_lib SHARED ${HEADER_FILES_PAR} ${SOURCE_FILES_PAR})

target_include_directories(sequential_lib PUBLIC sequential)
target_include_directories(parallel_lib PUBLIC parallel)