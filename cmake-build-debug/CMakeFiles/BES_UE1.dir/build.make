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
CMAKE_COMMAND = /opt/clion/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vik/Repos/bes2_ue1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vik/Repos/bes2_ue1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BES_UE1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BES_UE1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BES_UE1.dir/flags.make

CMakeFiles/BES_UE1.dir/main.c.o: CMakeFiles/BES_UE1.dir/flags.make
CMakeFiles/BES_UE1.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vik/Repos/bes2_ue1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/BES_UE1.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/BES_UE1.dir/main.c.o   -c /home/vik/Repos/bes2_ue1/main.c

CMakeFiles/BES_UE1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BES_UE1.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vik/Repos/bes2_ue1/main.c > CMakeFiles/BES_UE1.dir/main.c.i

CMakeFiles/BES_UE1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BES_UE1.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vik/Repos/bes2_ue1/main.c -o CMakeFiles/BES_UE1.dir/main.c.s

CMakeFiles/BES_UE1.dir/main.c.o.requires:

.PHONY : CMakeFiles/BES_UE1.dir/main.c.o.requires

CMakeFiles/BES_UE1.dir/main.c.o.provides: CMakeFiles/BES_UE1.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/BES_UE1.dir/build.make CMakeFiles/BES_UE1.dir/main.c.o.provides.build
.PHONY : CMakeFiles/BES_UE1.dir/main.c.o.provides

CMakeFiles/BES_UE1.dir/main.c.o.provides.build: CMakeFiles/BES_UE1.dir/main.c.o


CMakeFiles/BES_UE1.dir/search.c.o: CMakeFiles/BES_UE1.dir/flags.make
CMakeFiles/BES_UE1.dir/search.c.o: ../search.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vik/Repos/bes2_ue1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/BES_UE1.dir/search.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/BES_UE1.dir/search.c.o   -c /home/vik/Repos/bes2_ue1/search.c

CMakeFiles/BES_UE1.dir/search.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BES_UE1.dir/search.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vik/Repos/bes2_ue1/search.c > CMakeFiles/BES_UE1.dir/search.c.i

CMakeFiles/BES_UE1.dir/search.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BES_UE1.dir/search.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vik/Repos/bes2_ue1/search.c -o CMakeFiles/BES_UE1.dir/search.c.s

CMakeFiles/BES_UE1.dir/search.c.o.requires:

.PHONY : CMakeFiles/BES_UE1.dir/search.c.o.requires

CMakeFiles/BES_UE1.dir/search.c.o.provides: CMakeFiles/BES_UE1.dir/search.c.o.requires
	$(MAKE) -f CMakeFiles/BES_UE1.dir/build.make CMakeFiles/BES_UE1.dir/search.c.o.provides.build
.PHONY : CMakeFiles/BES_UE1.dir/search.c.o.provides

CMakeFiles/BES_UE1.dir/search.c.o.provides.build: CMakeFiles/BES_UE1.dir/search.c.o


# Object files for target BES_UE1
BES_UE1_OBJECTS = \
"CMakeFiles/BES_UE1.dir/main.c.o" \
"CMakeFiles/BES_UE1.dir/search.c.o"

# External object files for target BES_UE1
BES_UE1_EXTERNAL_OBJECTS =

BES_UE1: CMakeFiles/BES_UE1.dir/main.c.o
BES_UE1: CMakeFiles/BES_UE1.dir/search.c.o
BES_UE1: CMakeFiles/BES_UE1.dir/build.make
BES_UE1: CMakeFiles/BES_UE1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vik/Repos/bes2_ue1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable BES_UE1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BES_UE1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BES_UE1.dir/build: BES_UE1

.PHONY : CMakeFiles/BES_UE1.dir/build

CMakeFiles/BES_UE1.dir/requires: CMakeFiles/BES_UE1.dir/main.c.o.requires
CMakeFiles/BES_UE1.dir/requires: CMakeFiles/BES_UE1.dir/search.c.o.requires

.PHONY : CMakeFiles/BES_UE1.dir/requires

CMakeFiles/BES_UE1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BES_UE1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BES_UE1.dir/clean

CMakeFiles/BES_UE1.dir/depend:
	cd /home/vik/Repos/bes2_ue1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vik/Repos/bes2_ue1 /home/vik/Repos/bes2_ue1 /home/vik/Repos/bes2_ue1/cmake-build-debug /home/vik/Repos/bes2_ue1/cmake-build-debug /home/vik/Repos/bes2_ue1/cmake-build-debug/CMakeFiles/BES_UE1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BES_UE1.dir/depend

