# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ht/code/cross_make

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ht/code/cross_make

# Include any dependencies generated for this target.
include CMakeFiles/demo2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/demo2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/demo2.dir/flags.make

CMakeFiles/demo2.dir/main.cpp.o: CMakeFiles/demo2.dir/flags.make
CMakeFiles/demo2.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ht/code/cross_make/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/demo2.dir/main.cpp.o"
	/usr/bin/aarch64-linux-gnu-g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/demo2.dir/main.cpp.o -c /home/ht/code/cross_make/main.cpp

CMakeFiles/demo2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo2.dir/main.cpp.i"
	/usr/bin/aarch64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ht/code/cross_make/main.cpp > CMakeFiles/demo2.dir/main.cpp.i

CMakeFiles/demo2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo2.dir/main.cpp.s"
	/usr/bin/aarch64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ht/code/cross_make/main.cpp -o CMakeFiles/demo2.dir/main.cpp.s

# Object files for target demo2
demo2_OBJECTS = \
"CMakeFiles/demo2.dir/main.cpp.o"

# External object files for target demo2
demo2_EXTERNAL_OBJECTS =

demo2: CMakeFiles/demo2.dir/main.cpp.o
demo2: CMakeFiles/demo2.dir/build.make
demo2: CMakeFiles/demo2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ht/code/cross_make/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable demo2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/demo2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/demo2.dir/build: demo2

.PHONY : CMakeFiles/demo2.dir/build

CMakeFiles/demo2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/demo2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/demo2.dir/clean

CMakeFiles/demo2.dir/depend:
	cd /home/ht/code/cross_make && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ht/code/cross_make /home/ht/code/cross_make /home/ht/code/cross_make /home/ht/code/cross_make /home/ht/code/cross_make/CMakeFiles/demo2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/demo2.dir/depend

