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
CMAKE_SOURCE_DIR = /home/hussain/Desktop/CS2001-Data-Structures

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hussain/Desktop/CS2001-Data-Structures/build

# Include any dependencies generated for this target.
include CMakeFiles/speller.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/speller.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/speller.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/speller.dir/flags.make

CMakeFiles/speller.dir/speller.cpp.o: CMakeFiles/speller.dir/flags.make
CMakeFiles/speller.dir/speller.cpp.o: ../speller.cpp
CMakeFiles/speller.dir/speller.cpp.o: CMakeFiles/speller.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hussain/Desktop/CS2001-Data-Structures/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/speller.dir/speller.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/speller.dir/speller.cpp.o -MF CMakeFiles/speller.dir/speller.cpp.o.d -o CMakeFiles/speller.dir/speller.cpp.o -c /home/hussain/Desktop/CS2001-Data-Structures/speller.cpp

CMakeFiles/speller.dir/speller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/speller.dir/speller.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hussain/Desktop/CS2001-Data-Structures/speller.cpp > CMakeFiles/speller.dir/speller.cpp.i

CMakeFiles/speller.dir/speller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/speller.dir/speller.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hussain/Desktop/CS2001-Data-Structures/speller.cpp -o CMakeFiles/speller.dir/speller.cpp.s

# Object files for target speller
speller_OBJECTS = \
"CMakeFiles/speller.dir/speller.cpp.o"

# External object files for target speller
speller_EXTERNAL_OBJECTS =

speller: CMakeFiles/speller.dir/speller.cpp.o
speller: CMakeFiles/speller.dir/build.make
speller: Dictionary_lib/libdictionary.a
speller: HashMap_lib/libhashmap.a
speller: CMakeFiles/speller.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hussain/Desktop/CS2001-Data-Structures/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable speller"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/speller.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/speller.dir/build: speller
.PHONY : CMakeFiles/speller.dir/build

CMakeFiles/speller.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/speller.dir/cmake_clean.cmake
.PHONY : CMakeFiles/speller.dir/clean

CMakeFiles/speller.dir/depend:
	cd /home/hussain/Desktop/CS2001-Data-Structures/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hussain/Desktop/CS2001-Data-Structures /home/hussain/Desktop/CS2001-Data-Structures /home/hussain/Desktop/CS2001-Data-Structures/build /home/hussain/Desktop/CS2001-Data-Structures/build /home/hussain/Desktop/CS2001-Data-Structures/build/CMakeFiles/speller.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/speller.dir/depend

