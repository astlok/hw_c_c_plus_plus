include_directories(include)

file(GLOB sources "src/*.c")

add_executable(project ${sources})
