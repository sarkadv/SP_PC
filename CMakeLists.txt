cmake_minimum_required(VERSION 3.23)
project(SP_PC C)

set(CMAKE_C_STANDARD 90)

add_executable(SP_PC main.c dynamic_string_array.c dynamic_string_array.h err.c err.h textfile_loader.c textfile_loader.h word_hashtable.c)
