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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/zhangtao/Documents/GitHub/C-Playground/SpeechMS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zhangtao/Documents/GitHub/C-Playground/SpeechMS/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SpeechMS.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SpeechMS.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SpeechMS.dir/flags.make

CMakeFiles/SpeechMS.dir/main.cpp.o: CMakeFiles/SpeechMS.dir/flags.make
CMakeFiles/SpeechMS.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhangtao/Documents/GitHub/C-Playground/SpeechMS/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SpeechMS.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SpeechMS.dir/main.cpp.o -c /Users/zhangtao/Documents/GitHub/C-Playground/SpeechMS/main.cpp

CMakeFiles/SpeechMS.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SpeechMS.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhangtao/Documents/GitHub/C-Playground/SpeechMS/main.cpp > CMakeFiles/SpeechMS.dir/main.cpp.i

CMakeFiles/SpeechMS.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SpeechMS.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhangtao/Documents/GitHub/C-Playground/SpeechMS/main.cpp -o CMakeFiles/SpeechMS.dir/main.cpp.s

CMakeFiles/SpeechMS.dir/SpeakerManager.cpp.o: CMakeFiles/SpeechMS.dir/flags.make
CMakeFiles/SpeechMS.dir/SpeakerManager.cpp.o: ../SpeakerManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhangtao/Documents/GitHub/C-Playground/SpeechMS/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SpeechMS.dir/SpeakerManager.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SpeechMS.dir/SpeakerManager.cpp.o -c /Users/zhangtao/Documents/GitHub/C-Playground/SpeechMS/SpeakerManager.cpp

CMakeFiles/SpeechMS.dir/SpeakerManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SpeechMS.dir/SpeakerManager.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhangtao/Documents/GitHub/C-Playground/SpeechMS/SpeakerManager.cpp > CMakeFiles/SpeechMS.dir/SpeakerManager.cpp.i

CMakeFiles/SpeechMS.dir/SpeakerManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SpeechMS.dir/SpeakerManager.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhangtao/Documents/GitHub/C-Playground/SpeechMS/SpeakerManager.cpp -o CMakeFiles/SpeechMS.dir/SpeakerManager.cpp.s

# Object files for target SpeechMS
SpeechMS_OBJECTS = \
"CMakeFiles/SpeechMS.dir/main.cpp.o" \
"CMakeFiles/SpeechMS.dir/SpeakerManager.cpp.o"

# External object files for target SpeechMS
SpeechMS_EXTERNAL_OBJECTS =

SpeechMS: CMakeFiles/SpeechMS.dir/main.cpp.o
SpeechMS: CMakeFiles/SpeechMS.dir/SpeakerManager.cpp.o
SpeechMS: CMakeFiles/SpeechMS.dir/build.make
SpeechMS: CMakeFiles/SpeechMS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zhangtao/Documents/GitHub/C-Playground/SpeechMS/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable SpeechMS"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SpeechMS.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SpeechMS.dir/build: SpeechMS

.PHONY : CMakeFiles/SpeechMS.dir/build

CMakeFiles/SpeechMS.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SpeechMS.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SpeechMS.dir/clean

CMakeFiles/SpeechMS.dir/depend:
	cd /Users/zhangtao/Documents/GitHub/C-Playground/SpeechMS/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zhangtao/Documents/GitHub/C-Playground/SpeechMS /Users/zhangtao/Documents/GitHub/C-Playground/SpeechMS /Users/zhangtao/Documents/GitHub/C-Playground/SpeechMS/cmake-build-debug /Users/zhangtao/Documents/GitHub/C-Playground/SpeechMS/cmake-build-debug /Users/zhangtao/Documents/GitHub/C-Playground/SpeechMS/cmake-build-debug/CMakeFiles/SpeechMS.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SpeechMS.dir/depend

