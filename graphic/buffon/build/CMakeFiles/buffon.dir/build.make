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
CMAKE_SOURCE_DIR = /home/kei/workspace/c++/pi/graphic/buffon

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kei/workspace/c++/pi/graphic/buffon/build

# Include any dependencies generated for this target.
include CMakeFiles/buffon.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/buffon.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/buffon.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/buffon.dir/flags.make

CMakeFiles/buffon.dir/buffon.cpp.o: CMakeFiles/buffon.dir/flags.make
CMakeFiles/buffon.dir/buffon.cpp.o: ../buffon.cpp
CMakeFiles/buffon.dir/buffon.cpp.o: CMakeFiles/buffon.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kei/workspace/c++/pi/graphic/buffon/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/buffon.dir/buffon.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/buffon.dir/buffon.cpp.o -MF CMakeFiles/buffon.dir/buffon.cpp.o.d -o CMakeFiles/buffon.dir/buffon.cpp.o -c /home/kei/workspace/c++/pi/graphic/buffon/buffon.cpp

CMakeFiles/buffon.dir/buffon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/buffon.dir/buffon.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kei/workspace/c++/pi/graphic/buffon/buffon.cpp > CMakeFiles/buffon.dir/buffon.cpp.i

CMakeFiles/buffon.dir/buffon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/buffon.dir/buffon.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kei/workspace/c++/pi/graphic/buffon/buffon.cpp -o CMakeFiles/buffon.dir/buffon.cpp.s

# Object files for target buffon
buffon_OBJECTS = \
"CMakeFiles/buffon.dir/buffon.cpp.o"

# External object files for target buffon
buffon_EXTERNAL_OBJECTS =

buffon: CMakeFiles/buffon.dir/buffon.cpp.o
buffon: CMakeFiles/buffon.dir/build.make
buffon: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so.2.5.1
buffon: /usr/lib/x86_64-linux-gnu/libsfml-window.so.2.5.1
buffon: /usr/lib/x86_64-linux-gnu/libsfml-system.so.2.5.1
buffon: CMakeFiles/buffon.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kei/workspace/c++/pi/graphic/buffon/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable buffon"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/buffon.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/buffon.dir/build: buffon
.PHONY : CMakeFiles/buffon.dir/build

CMakeFiles/buffon.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/buffon.dir/cmake_clean.cmake
.PHONY : CMakeFiles/buffon.dir/clean

CMakeFiles/buffon.dir/depend:
	cd /home/kei/workspace/c++/pi/graphic/buffon/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kei/workspace/c++/pi/graphic/buffon /home/kei/workspace/c++/pi/graphic/buffon /home/kei/workspace/c++/pi/graphic/buffon/build /home/kei/workspace/c++/pi/graphic/buffon/build /home/kei/workspace/c++/pi/graphic/buffon/build/CMakeFiles/buffon.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/buffon.dir/depend

