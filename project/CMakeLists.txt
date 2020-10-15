include_directories(include)
set(PROJECT_SOURCE_FILES
        src/main.c
        src/memory.c
        src/parse_user_email.c)
add_executable(project src/main.c src/memory.c src/parse_user_email.c)
