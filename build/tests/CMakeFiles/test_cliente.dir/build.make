# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tom/Desktop/Hotelucho

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tom/Desktop/Hotelucho/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/test_cliente.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/test_cliente.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/test_cliente.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/test_cliente.dir/flags.make

tests/CMakeFiles/test_cliente.dir/test_cliente.cpp.o: tests/CMakeFiles/test_cliente.dir/flags.make
tests/CMakeFiles/test_cliente.dir/test_cliente.cpp.o: ../tests/test_cliente.cpp
tests/CMakeFiles/test_cliente.dir/test_cliente.cpp.o: tests/CMakeFiles/test_cliente.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tom/Desktop/Hotelucho/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/test_cliente.dir/test_cliente.cpp.o"
	cd /home/tom/Desktop/Hotelucho/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/test_cliente.dir/test_cliente.cpp.o -MF CMakeFiles/test_cliente.dir/test_cliente.cpp.o.d -o CMakeFiles/test_cliente.dir/test_cliente.cpp.o -c /home/tom/Desktop/Hotelucho/tests/test_cliente.cpp

tests/CMakeFiles/test_cliente.dir/test_cliente.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_cliente.dir/test_cliente.cpp.i"
	cd /home/tom/Desktop/Hotelucho/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tom/Desktop/Hotelucho/tests/test_cliente.cpp > CMakeFiles/test_cliente.dir/test_cliente.cpp.i

tests/CMakeFiles/test_cliente.dir/test_cliente.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_cliente.dir/test_cliente.cpp.s"
	cd /home/tom/Desktop/Hotelucho/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tom/Desktop/Hotelucho/tests/test_cliente.cpp -o CMakeFiles/test_cliente.dir/test_cliente.cpp.s

tests/CMakeFiles/test_cliente.dir/__/cliente.cpp.o: tests/CMakeFiles/test_cliente.dir/flags.make
tests/CMakeFiles/test_cliente.dir/__/cliente.cpp.o: ../cliente.cpp
tests/CMakeFiles/test_cliente.dir/__/cliente.cpp.o: tests/CMakeFiles/test_cliente.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tom/Desktop/Hotelucho/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/CMakeFiles/test_cliente.dir/__/cliente.cpp.o"
	cd /home/tom/Desktop/Hotelucho/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/test_cliente.dir/__/cliente.cpp.o -MF CMakeFiles/test_cliente.dir/__/cliente.cpp.o.d -o CMakeFiles/test_cliente.dir/__/cliente.cpp.o -c /home/tom/Desktop/Hotelucho/cliente.cpp

tests/CMakeFiles/test_cliente.dir/__/cliente.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_cliente.dir/__/cliente.cpp.i"
	cd /home/tom/Desktop/Hotelucho/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tom/Desktop/Hotelucho/cliente.cpp > CMakeFiles/test_cliente.dir/__/cliente.cpp.i

tests/CMakeFiles/test_cliente.dir/__/cliente.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_cliente.dir/__/cliente.cpp.s"
	cd /home/tom/Desktop/Hotelucho/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tom/Desktop/Hotelucho/cliente.cpp -o CMakeFiles/test_cliente.dir/__/cliente.cpp.s

# Object files for target test_cliente
test_cliente_OBJECTS = \
"CMakeFiles/test_cliente.dir/test_cliente.cpp.o" \
"CMakeFiles/test_cliente.dir/__/cliente.cpp.o"

# External object files for target test_cliente
test_cliente_EXTERNAL_OBJECTS =

tests/test_cliente: tests/CMakeFiles/test_cliente.dir/test_cliente.cpp.o
tests/test_cliente: tests/CMakeFiles/test_cliente.dir/__/cliente.cpp.o
tests/test_cliente: tests/CMakeFiles/test_cliente.dir/build.make
tests/test_cliente: lib/libgtest.a
tests/test_cliente: lib/libgtest_main.a
tests/test_cliente: lib/libgtest.a
tests/test_cliente: tests/CMakeFiles/test_cliente.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tom/Desktop/Hotelucho/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable test_cliente"
	cd /home/tom/Desktop/Hotelucho/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_cliente.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/test_cliente.dir/build: tests/test_cliente
.PHONY : tests/CMakeFiles/test_cliente.dir/build

tests/CMakeFiles/test_cliente.dir/clean:
	cd /home/tom/Desktop/Hotelucho/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/test_cliente.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/test_cliente.dir/clean

tests/CMakeFiles/test_cliente.dir/depend:
	cd /home/tom/Desktop/Hotelucho/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tom/Desktop/Hotelucho /home/tom/Desktop/Hotelucho/tests /home/tom/Desktop/Hotelucho/build /home/tom/Desktop/Hotelucho/build/tests /home/tom/Desktop/Hotelucho/build/tests/CMakeFiles/test_cliente.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/test_cliente.dir/depend
