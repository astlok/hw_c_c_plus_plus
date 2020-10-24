include_directories(include)
set(PROJECT_SOURCE_FILES
        src/main.c
        src/utils.c
        src/sequential.c
        src/parallel.c)

add_executable(project ${PROJECT_SOURCE_FILES})
