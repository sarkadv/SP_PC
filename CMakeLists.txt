cmake_minimum_required(VERSION 3.23)
project(SP_PC C)

set(CMAKE_C_STANDARD 90)

add_executable(SP_PC spamid.c dynamic_string_array.c dynamic_string_array.h err.c err.h trainfile_loader.c trainfile_loader.h word_hashtable.c word_hashtable.h eval.c eval.h testfile_loader.c testfile_loader.h output.c output.h)
