# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/LeetCodePractise/LeetCodePractise

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/LeetCodePractise/LeetCodePractise/build

# Include any dependencies generated for this target.
include src/CMakeFiles/LeetCodePractice_shared.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/LeetCodePractice_shared.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/LeetCodePractice_shared.dir/flags.make

src/CMakeFiles/LeetCodePractice_shared.dir/easy/array_algo_easy.cpp.o: src/CMakeFiles/LeetCodePractice_shared.dir/flags.make
src/CMakeFiles/LeetCodePractice_shared.dir/easy/array_algo_easy.cpp.o: ../src/easy/array_algo_easy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/LeetCodePractise/LeetCodePractise/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/LeetCodePractice_shared.dir/easy/array_algo_easy.cpp.o"
	cd /home/LeetCodePractise/LeetCodePractise/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LeetCodePractice_shared.dir/easy/array_algo_easy.cpp.o -c /home/LeetCodePractise/LeetCodePractise/src/easy/array_algo_easy.cpp

src/CMakeFiles/LeetCodePractice_shared.dir/easy/array_algo_easy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LeetCodePractice_shared.dir/easy/array_algo_easy.cpp.i"
	cd /home/LeetCodePractise/LeetCodePractise/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/LeetCodePractise/LeetCodePractise/src/easy/array_algo_easy.cpp > CMakeFiles/LeetCodePractice_shared.dir/easy/array_algo_easy.cpp.i

src/CMakeFiles/LeetCodePractice_shared.dir/easy/array_algo_easy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LeetCodePractice_shared.dir/easy/array_algo_easy.cpp.s"
	cd /home/LeetCodePractise/LeetCodePractise/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/LeetCodePractise/LeetCodePractise/src/easy/array_algo_easy.cpp -o CMakeFiles/LeetCodePractice_shared.dir/easy/array_algo_easy.cpp.s

src/CMakeFiles/LeetCodePractice_shared.dir/easy/array_algo_easy.cpp.o.requires:

.PHONY : src/CMakeFiles/LeetCodePractice_shared.dir/easy/array_algo_easy.cpp.o.requires

src/CMakeFiles/LeetCodePractice_shared.dir/easy/array_algo_easy.cpp.o.provides: src/CMakeFiles/LeetCodePractice_shared.dir/easy/array_algo_easy.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/LeetCodePractice_shared.dir/build.make src/CMakeFiles/LeetCodePractice_shared.dir/easy/array_algo_easy.cpp.o.provides.build
.PHONY : src/CMakeFiles/LeetCodePractice_shared.dir/easy/array_algo_easy.cpp.o.provides

src/CMakeFiles/LeetCodePractice_shared.dir/easy/array_algo_easy.cpp.o.provides.build: src/CMakeFiles/LeetCodePractice_shared.dir/easy/array_algo_easy.cpp.o


src/CMakeFiles/LeetCodePractice_shared.dir/hard/array_algo_hard.cpp.o: src/CMakeFiles/LeetCodePractice_shared.dir/flags.make
src/CMakeFiles/LeetCodePractice_shared.dir/hard/array_algo_hard.cpp.o: ../src/hard/array_algo_hard.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/LeetCodePractise/LeetCodePractise/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/LeetCodePractice_shared.dir/hard/array_algo_hard.cpp.o"
	cd /home/LeetCodePractise/LeetCodePractise/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LeetCodePractice_shared.dir/hard/array_algo_hard.cpp.o -c /home/LeetCodePractise/LeetCodePractise/src/hard/array_algo_hard.cpp

src/CMakeFiles/LeetCodePractice_shared.dir/hard/array_algo_hard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LeetCodePractice_shared.dir/hard/array_algo_hard.cpp.i"
	cd /home/LeetCodePractise/LeetCodePractise/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/LeetCodePractise/LeetCodePractise/src/hard/array_algo_hard.cpp > CMakeFiles/LeetCodePractice_shared.dir/hard/array_algo_hard.cpp.i

src/CMakeFiles/LeetCodePractice_shared.dir/hard/array_algo_hard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LeetCodePractice_shared.dir/hard/array_algo_hard.cpp.s"
	cd /home/LeetCodePractise/LeetCodePractise/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/LeetCodePractise/LeetCodePractise/src/hard/array_algo_hard.cpp -o CMakeFiles/LeetCodePractice_shared.dir/hard/array_algo_hard.cpp.s

src/CMakeFiles/LeetCodePractice_shared.dir/hard/array_algo_hard.cpp.o.requires:

.PHONY : src/CMakeFiles/LeetCodePractice_shared.dir/hard/array_algo_hard.cpp.o.requires

src/CMakeFiles/LeetCodePractice_shared.dir/hard/array_algo_hard.cpp.o.provides: src/CMakeFiles/LeetCodePractice_shared.dir/hard/array_algo_hard.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/LeetCodePractice_shared.dir/build.make src/CMakeFiles/LeetCodePractice_shared.dir/hard/array_algo_hard.cpp.o.provides.build
.PHONY : src/CMakeFiles/LeetCodePractice_shared.dir/hard/array_algo_hard.cpp.o.provides

src/CMakeFiles/LeetCodePractice_shared.dir/hard/array_algo_hard.cpp.o.provides.build: src/CMakeFiles/LeetCodePractice_shared.dir/hard/array_algo_hard.cpp.o


src/CMakeFiles/LeetCodePractice_shared.dir/normal/array_algo_normal.cpp.o: src/CMakeFiles/LeetCodePractice_shared.dir/flags.make
src/CMakeFiles/LeetCodePractice_shared.dir/normal/array_algo_normal.cpp.o: ../src/normal/array_algo_normal.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/LeetCodePractise/LeetCodePractise/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/LeetCodePractice_shared.dir/normal/array_algo_normal.cpp.o"
	cd /home/LeetCodePractise/LeetCodePractise/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LeetCodePractice_shared.dir/normal/array_algo_normal.cpp.o -c /home/LeetCodePractise/LeetCodePractise/src/normal/array_algo_normal.cpp

src/CMakeFiles/LeetCodePractice_shared.dir/normal/array_algo_normal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LeetCodePractice_shared.dir/normal/array_algo_normal.cpp.i"
	cd /home/LeetCodePractise/LeetCodePractise/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/LeetCodePractise/LeetCodePractise/src/normal/array_algo_normal.cpp > CMakeFiles/LeetCodePractice_shared.dir/normal/array_algo_normal.cpp.i

src/CMakeFiles/LeetCodePractice_shared.dir/normal/array_algo_normal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LeetCodePractice_shared.dir/normal/array_algo_normal.cpp.s"
	cd /home/LeetCodePractise/LeetCodePractise/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/LeetCodePractise/LeetCodePractise/src/normal/array_algo_normal.cpp -o CMakeFiles/LeetCodePractice_shared.dir/normal/array_algo_normal.cpp.s

src/CMakeFiles/LeetCodePractice_shared.dir/normal/array_algo_normal.cpp.o.requires:

.PHONY : src/CMakeFiles/LeetCodePractice_shared.dir/normal/array_algo_normal.cpp.o.requires

src/CMakeFiles/LeetCodePractice_shared.dir/normal/array_algo_normal.cpp.o.provides: src/CMakeFiles/LeetCodePractice_shared.dir/normal/array_algo_normal.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/LeetCodePractice_shared.dir/build.make src/CMakeFiles/LeetCodePractice_shared.dir/normal/array_algo_normal.cpp.o.provides.build
.PHONY : src/CMakeFiles/LeetCodePractice_shared.dir/normal/array_algo_normal.cpp.o.provides

src/CMakeFiles/LeetCodePractice_shared.dir/normal/array_algo_normal.cpp.o.provides.build: src/CMakeFiles/LeetCodePractice_shared.dir/normal/array_algo_normal.cpp.o


# Object files for target LeetCodePractice_shared
LeetCodePractice_shared_OBJECTS = \
"CMakeFiles/LeetCodePractice_shared.dir/easy/array_algo_easy.cpp.o" \
"CMakeFiles/LeetCodePractice_shared.dir/hard/array_algo_hard.cpp.o" \
"CMakeFiles/LeetCodePractice_shared.dir/normal/array_algo_normal.cpp.o"

# External object files for target LeetCodePractice_shared
LeetCodePractice_shared_EXTERNAL_OBJECTS =

src/libLeetCodePractice_shared.so: src/CMakeFiles/LeetCodePractice_shared.dir/easy/array_algo_easy.cpp.o
src/libLeetCodePractice_shared.so: src/CMakeFiles/LeetCodePractice_shared.dir/hard/array_algo_hard.cpp.o
src/libLeetCodePractice_shared.so: src/CMakeFiles/LeetCodePractice_shared.dir/normal/array_algo_normal.cpp.o
src/libLeetCodePractice_shared.so: src/CMakeFiles/LeetCodePractice_shared.dir/build.make
src/libLeetCodePractice_shared.so: src/CMakeFiles/LeetCodePractice_shared.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/LeetCodePractise/LeetCodePractise/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX shared library libLeetCodePractice_shared.so"
	cd /home/LeetCodePractise/LeetCodePractise/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LeetCodePractice_shared.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/LeetCodePractice_shared.dir/build: src/libLeetCodePractice_shared.so

.PHONY : src/CMakeFiles/LeetCodePractice_shared.dir/build

src/CMakeFiles/LeetCodePractice_shared.dir/requires: src/CMakeFiles/LeetCodePractice_shared.dir/easy/array_algo_easy.cpp.o.requires
src/CMakeFiles/LeetCodePractice_shared.dir/requires: src/CMakeFiles/LeetCodePractice_shared.dir/hard/array_algo_hard.cpp.o.requires
src/CMakeFiles/LeetCodePractice_shared.dir/requires: src/CMakeFiles/LeetCodePractice_shared.dir/normal/array_algo_normal.cpp.o.requires

.PHONY : src/CMakeFiles/LeetCodePractice_shared.dir/requires

src/CMakeFiles/LeetCodePractice_shared.dir/clean:
	cd /home/LeetCodePractise/LeetCodePractise/build/src && $(CMAKE_COMMAND) -P CMakeFiles/LeetCodePractice_shared.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/LeetCodePractice_shared.dir/clean

src/CMakeFiles/LeetCodePractice_shared.dir/depend:
	cd /home/LeetCodePractise/LeetCodePractise/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/LeetCodePractise/LeetCodePractise /home/LeetCodePractise/LeetCodePractise/src /home/LeetCodePractise/LeetCodePractise/build /home/LeetCodePractise/LeetCodePractise/build/src /home/LeetCodePractise/LeetCodePractise/build/src/CMakeFiles/LeetCodePractice_shared.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/LeetCodePractice_shared.dir/depend

