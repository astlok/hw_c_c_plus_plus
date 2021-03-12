include_directories(include)

set(PROJECT_SOURCE_FILES
        src/main.c)

add_executable(project ${PROJECT_SOURCE_FILES})

target_link_libraries(project sequential_lib parallel_lib)
