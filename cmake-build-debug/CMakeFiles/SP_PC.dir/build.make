# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/saridvorakova/CLionProjects/SP_PC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/saridvorakova/CLionProjects/SP_PC/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SP_PC.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SP_PC.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SP_PC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SP_PC.dir/flags.make

CMakeFiles/SP_PC.dir/spamid.c.o: CMakeFiles/SP_PC.dir/flags.make
CMakeFiles/SP_PC.dir/spamid.c.o: ../spamid.c
CMakeFiles/SP_PC.dir/spamid.c.o: CMakeFiles/SP_PC.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/saridvorakova/CLionProjects/SP_PC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/SP_PC.dir/spamid.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SP_PC.dir/spamid.c.o -MF CMakeFiles/SP_PC.dir/spamid.c.o.d -o CMakeFiles/SP_PC.dir/spamid.c.o -c /Users/saridvorakova/CLionProjects/SP_PC/spamid.c

CMakeFiles/SP_PC.dir/spamid.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SP_PC.dir/spamid.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/saridvorakova/CLionProjects/SP_PC/spamid.c > CMakeFiles/SP_PC.dir/spamid.c.i

CMakeFiles/SP_PC.dir/spamid.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SP_PC.dir/spamid.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/saridvorakova/CLionProjects/SP_PC/spamid.c -o CMakeFiles/SP_PC.dir/spamid.c.s

CMakeFiles/SP_PC.dir/dynamic_string_array.c.o: CMakeFiles/SP_PC.dir/flags.make
CMakeFiles/SP_PC.dir/dynamic_string_array.c.o: ../dynamic_string_array.c
CMakeFiles/SP_PC.dir/dynamic_string_array.c.o: CMakeFiles/SP_PC.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/saridvorakova/CLionProjects/SP_PC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/SP_PC.dir/dynamic_string_array.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SP_PC.dir/dynamic_string_array.c.o -MF CMakeFiles/SP_PC.dir/dynamic_string_array.c.o.d -o CMakeFiles/SP_PC.dir/dynamic_string_array.c.o -c /Users/saridvorakova/CLionProjects/SP_PC/dynamic_string_array.c

CMakeFiles/SP_PC.dir/dynamic_string_array.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SP_PC.dir/dynamic_string_array.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/saridvorakova/CLionProjects/SP_PC/dynamic_string_array.c > CMakeFiles/SP_PC.dir/dynamic_string_array.c.i

CMakeFiles/SP_PC.dir/dynamic_string_array.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SP_PC.dir/dynamic_string_array.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/saridvorakova/CLionProjects/SP_PC/dynamic_string_array.c -o CMakeFiles/SP_PC.dir/dynamic_string_array.c.s

CMakeFiles/SP_PC.dir/err.c.o: CMakeFiles/SP_PC.dir/flags.make
CMakeFiles/SP_PC.dir/err.c.o: ../err.c
CMakeFiles/SP_PC.dir/err.c.o: CMakeFiles/SP_PC.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/saridvorakova/CLionProjects/SP_PC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/SP_PC.dir/err.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SP_PC.dir/err.c.o -MF CMakeFiles/SP_PC.dir/err.c.o.d -o CMakeFiles/SP_PC.dir/err.c.o -c /Users/saridvorakova/CLionProjects/SP_PC/err.c

CMakeFiles/SP_PC.dir/err.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SP_PC.dir/err.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/saridvorakova/CLionProjects/SP_PC/err.c > CMakeFiles/SP_PC.dir/err.c.i

CMakeFiles/SP_PC.dir/err.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SP_PC.dir/err.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/saridvorakova/CLionProjects/SP_PC/err.c -o CMakeFiles/SP_PC.dir/err.c.s

CMakeFiles/SP_PC.dir/trainfile_loader.c.o: CMakeFiles/SP_PC.dir/flags.make
CMakeFiles/SP_PC.dir/trainfile_loader.c.o: ../trainfile_loader.c
CMakeFiles/SP_PC.dir/trainfile_loader.c.o: CMakeFiles/SP_PC.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/saridvorakova/CLionProjects/SP_PC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/SP_PC.dir/trainfile_loader.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SP_PC.dir/trainfile_loader.c.o -MF CMakeFiles/SP_PC.dir/trainfile_loader.c.o.d -o CMakeFiles/SP_PC.dir/trainfile_loader.c.o -c /Users/saridvorakova/CLionProjects/SP_PC/trainfile_loader.c

CMakeFiles/SP_PC.dir/trainfile_loader.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SP_PC.dir/trainfile_loader.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/saridvorakova/CLionProjects/SP_PC/trainfile_loader.c > CMakeFiles/SP_PC.dir/trainfile_loader.c.i

CMakeFiles/SP_PC.dir/trainfile_loader.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SP_PC.dir/trainfile_loader.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/saridvorakova/CLionProjects/SP_PC/trainfile_loader.c -o CMakeFiles/SP_PC.dir/trainfile_loader.c.s

CMakeFiles/SP_PC.dir/word_hashtable.c.o: CMakeFiles/SP_PC.dir/flags.make
CMakeFiles/SP_PC.dir/word_hashtable.c.o: ../word_hashtable.c
CMakeFiles/SP_PC.dir/word_hashtable.c.o: CMakeFiles/SP_PC.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/saridvorakova/CLionProjects/SP_PC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/SP_PC.dir/word_hashtable.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SP_PC.dir/word_hashtable.c.o -MF CMakeFiles/SP_PC.dir/word_hashtable.c.o.d -o CMakeFiles/SP_PC.dir/word_hashtable.c.o -c /Users/saridvorakova/CLionProjects/SP_PC/word_hashtable.c

CMakeFiles/SP_PC.dir/word_hashtable.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SP_PC.dir/word_hashtable.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/saridvorakova/CLionProjects/SP_PC/word_hashtable.c > CMakeFiles/SP_PC.dir/word_hashtable.c.i

CMakeFiles/SP_PC.dir/word_hashtable.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SP_PC.dir/word_hashtable.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/saridvorakova/CLionProjects/SP_PC/word_hashtable.c -o CMakeFiles/SP_PC.dir/word_hashtable.c.s

CMakeFiles/SP_PC.dir/eval.c.o: CMakeFiles/SP_PC.dir/flags.make
CMakeFiles/SP_PC.dir/eval.c.o: ../eval.c
CMakeFiles/SP_PC.dir/eval.c.o: CMakeFiles/SP_PC.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/saridvorakova/CLionProjects/SP_PC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/SP_PC.dir/eval.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SP_PC.dir/eval.c.o -MF CMakeFiles/SP_PC.dir/eval.c.o.d -o CMakeFiles/SP_PC.dir/eval.c.o -c /Users/saridvorakova/CLionProjects/SP_PC/eval.c

CMakeFiles/SP_PC.dir/eval.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SP_PC.dir/eval.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/saridvorakova/CLionProjects/SP_PC/eval.c > CMakeFiles/SP_PC.dir/eval.c.i

CMakeFiles/SP_PC.dir/eval.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SP_PC.dir/eval.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/saridvorakova/CLionProjects/SP_PC/eval.c -o CMakeFiles/SP_PC.dir/eval.c.s

CMakeFiles/SP_PC.dir/testfile_loader.c.o: CMakeFiles/SP_PC.dir/flags.make
CMakeFiles/SP_PC.dir/testfile_loader.c.o: ../testfile_loader.c
CMakeFiles/SP_PC.dir/testfile_loader.c.o: CMakeFiles/SP_PC.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/saridvorakova/CLionProjects/SP_PC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/SP_PC.dir/testfile_loader.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SP_PC.dir/testfile_loader.c.o -MF CMakeFiles/SP_PC.dir/testfile_loader.c.o.d -o CMakeFiles/SP_PC.dir/testfile_loader.c.o -c /Users/saridvorakova/CLionProjects/SP_PC/testfile_loader.c

CMakeFiles/SP_PC.dir/testfile_loader.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SP_PC.dir/testfile_loader.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/saridvorakova/CLionProjects/SP_PC/testfile_loader.c > CMakeFiles/SP_PC.dir/testfile_loader.c.i

CMakeFiles/SP_PC.dir/testfile_loader.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SP_PC.dir/testfile_loader.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/saridvorakova/CLionProjects/SP_PC/testfile_loader.c -o CMakeFiles/SP_PC.dir/testfile_loader.c.s

CMakeFiles/SP_PC.dir/output.c.o: CMakeFiles/SP_PC.dir/flags.make
CMakeFiles/SP_PC.dir/output.c.o: ../output.c
CMakeFiles/SP_PC.dir/output.c.o: CMakeFiles/SP_PC.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/saridvorakova/CLionProjects/SP_PC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/SP_PC.dir/output.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SP_PC.dir/output.c.o -MF CMakeFiles/SP_PC.dir/output.c.o.d -o CMakeFiles/SP_PC.dir/output.c.o -c /Users/saridvorakova/CLionProjects/SP_PC/output.c

CMakeFiles/SP_PC.dir/output.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SP_PC.dir/output.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/saridvorakova/CLionProjects/SP_PC/output.c > CMakeFiles/SP_PC.dir/output.c.i

CMakeFiles/SP_PC.dir/output.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SP_PC.dir/output.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/saridvorakova/CLionProjects/SP_PC/output.c -o CMakeFiles/SP_PC.dir/output.c.s

# Object files for target SP_PC
SP_PC_OBJECTS = \
"CMakeFiles/SP_PC.dir/spamid.c.o" \
"CMakeFiles/SP_PC.dir/dynamic_string_array.c.o" \
"CMakeFiles/SP_PC.dir/err.c.o" \
"CMakeFiles/SP_PC.dir/trainfile_loader.c.o" \
"CMakeFiles/SP_PC.dir/word_hashtable.c.o" \
"CMakeFiles/SP_PC.dir/eval.c.o" \
"CMakeFiles/SP_PC.dir/testfile_loader.c.o" \
"CMakeFiles/SP_PC.dir/output.c.o"

# External object files for target SP_PC
SP_PC_EXTERNAL_OBJECTS =

SP_PC: CMakeFiles/SP_PC.dir/spamid.c.o
SP_PC: CMakeFiles/SP_PC.dir/dynamic_string_array.c.o
SP_PC: CMakeFiles/SP_PC.dir/err.c.o
SP_PC: CMakeFiles/SP_PC.dir/trainfile_loader.c.o
SP_PC: CMakeFiles/SP_PC.dir/word_hashtable.c.o
SP_PC: CMakeFiles/SP_PC.dir/eval.c.o
SP_PC: CMakeFiles/SP_PC.dir/testfile_loader.c.o
SP_PC: CMakeFiles/SP_PC.dir/output.c.o
SP_PC: CMakeFiles/SP_PC.dir/build.make
SP_PC: CMakeFiles/SP_PC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/saridvorakova/CLionProjects/SP_PC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking C executable SP_PC"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SP_PC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SP_PC.dir/build: SP_PC
.PHONY : CMakeFiles/SP_PC.dir/build

CMakeFiles/SP_PC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SP_PC.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SP_PC.dir/clean

CMakeFiles/SP_PC.dir/depend:
	cd /Users/saridvorakova/CLionProjects/SP_PC/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/saridvorakova/CLionProjects/SP_PC /Users/saridvorakova/CLionProjects/SP_PC /Users/saridvorakova/CLionProjects/SP_PC/cmake-build-debug /Users/saridvorakova/CLionProjects/SP_PC/cmake-build-debug /Users/saridvorakova/CLionProjects/SP_PC/cmake-build-debug/CMakeFiles/SP_PC.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SP_PC.dir/depend

