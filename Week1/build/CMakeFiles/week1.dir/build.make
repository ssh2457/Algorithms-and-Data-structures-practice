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
CMAKE_SOURCE_DIR = /home/ssh2457/Documents/Algorithms-and-Data-structures-practice/Week1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ssh2457/Documents/Algorithms-and-Data-structures-practice/Week1/build

# Include any dependencies generated for this target.
include CMakeFiles/week1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/week1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/week1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/week1.dir/flags.make

CMakeFiles/week1.dir/test.cpp.o: CMakeFiles/week1.dir/flags.make
CMakeFiles/week1.dir/test.cpp.o: ../test.cpp
CMakeFiles/week1.dir/test.cpp.o: CMakeFiles/week1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ssh2457/Documents/Algorithms-and-Data-structures-practice/Week1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/week1.dir/test.cpp.o"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/week1.dir/test.cpp.o -MF CMakeFiles/week1.dir/test.cpp.o.d -o CMakeFiles/week1.dir/test.cpp.o -c /home/ssh2457/Documents/Algorithms-and-Data-structures-practice/Week1/test.cpp

CMakeFiles/week1.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/week1.dir/test.cpp.i"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ssh2457/Documents/Algorithms-and-Data-structures-practice/Week1/test.cpp > CMakeFiles/week1.dir/test.cpp.i

CMakeFiles/week1.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/week1.dir/test.cpp.s"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ssh2457/Documents/Algorithms-and-Data-structures-practice/Week1/test.cpp -o CMakeFiles/week1.dir/test.cpp.s

CMakeFiles/week1.dir/MyStack.cpp.o: CMakeFiles/week1.dir/flags.make
CMakeFiles/week1.dir/MyStack.cpp.o: ../MyStack.cpp
CMakeFiles/week1.dir/MyStack.cpp.o: CMakeFiles/week1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ssh2457/Documents/Algorithms-and-Data-structures-practice/Week1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/week1.dir/MyStack.cpp.o"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/week1.dir/MyStack.cpp.o -MF CMakeFiles/week1.dir/MyStack.cpp.o.d -o CMakeFiles/week1.dir/MyStack.cpp.o -c /home/ssh2457/Documents/Algorithms-and-Data-structures-practice/Week1/MyStack.cpp

CMakeFiles/week1.dir/MyStack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/week1.dir/MyStack.cpp.i"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ssh2457/Documents/Algorithms-and-Data-structures-practice/Week1/MyStack.cpp > CMakeFiles/week1.dir/MyStack.cpp.i

CMakeFiles/week1.dir/MyStack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/week1.dir/MyStack.cpp.s"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ssh2457/Documents/Algorithms-and-Data-structures-practice/Week1/MyStack.cpp -o CMakeFiles/week1.dir/MyStack.cpp.s

# Object files for target week1
week1_OBJECTS = \
"CMakeFiles/week1.dir/test.cpp.o" \
"CMakeFiles/week1.dir/MyStack.cpp.o"

# External object files for target week1
week1_EXTERNAL_OBJECTS =

week1: CMakeFiles/week1.dir/test.cpp.o
week1: CMakeFiles/week1.dir/MyStack.cpp.o
week1: CMakeFiles/week1.dir/build.make
week1: CMakeFiles/week1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ssh2457/Documents/Algorithms-and-Data-structures-practice/Week1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable week1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/week1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/week1.dir/build: week1
.PHONY : CMakeFiles/week1.dir/build

CMakeFiles/week1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/week1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/week1.dir/clean

CMakeFiles/week1.dir/depend:
	cd /home/ssh2457/Documents/Algorithms-and-Data-structures-practice/Week1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ssh2457/Documents/Algorithms-and-Data-structures-practice/Week1 /home/ssh2457/Documents/Algorithms-and-Data-structures-practice/Week1 /home/ssh2457/Documents/Algorithms-and-Data-structures-practice/Week1/build /home/ssh2457/Documents/Algorithms-and-Data-structures-practice/Week1/build /home/ssh2457/Documents/Algorithms-and-Data-structures-practice/Week1/build/CMakeFiles/week1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/week1.dir/depend

