project(lelcode)
set(CMAKE_C_FLAGS_DEBUG "-g -O0 -fsanitize=address -Wall -Wextra")
set(FILES
    lelcode.c
    tokenizer.c tokenizer.h)
add_executable(lelcode ${FILES})
