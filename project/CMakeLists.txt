include_directories(include)
include_directories(../lib/parallel)
include_directories(../lib/sequential)

set(PROJECT_SOURCE_FILES
        src/main.c)


add_executable(project ${PROJECT_SOURCE_FILES})

target_link_libraries(project sequential_lib parallel_lib)
