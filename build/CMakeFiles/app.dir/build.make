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
CMAKE_SOURCE_DIR = /home/arnav/courses/4/cg/ass1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arnav/courses/4/cg/ass1/build

# Include any dependencies generated for this target.
include CMakeFiles/app.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/app.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/app.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/app.dir/flags.make

CMakeFiles/app.dir/src/background.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/background.cpp.o: ../src/background.cpp
CMakeFiles/app.dir/src/background.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arnav/courses/4/cg/ass1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/app.dir/src/background.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/src/background.cpp.o -MF CMakeFiles/app.dir/src/background.cpp.o.d -o CMakeFiles/app.dir/src/background.cpp.o -c /home/arnav/courses/4/cg/ass1/src/background.cpp

CMakeFiles/app.dir/src/background.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/background.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arnav/courses/4/cg/ass1/src/background.cpp > CMakeFiles/app.dir/src/background.cpp.i

CMakeFiles/app.dir/src/background.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/background.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arnav/courses/4/cg/ass1/src/background.cpp -o CMakeFiles/app.dir/src/background.cpp.s

CMakeFiles/app.dir/src/game.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/game.cpp.o: ../src/game.cpp
CMakeFiles/app.dir/src/game.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arnav/courses/4/cg/ass1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/app.dir/src/game.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/src/game.cpp.o -MF CMakeFiles/app.dir/src/game.cpp.o.d -o CMakeFiles/app.dir/src/game.cpp.o -c /home/arnav/courses/4/cg/ass1/src/game.cpp

CMakeFiles/app.dir/src/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arnav/courses/4/cg/ass1/src/game.cpp > CMakeFiles/app.dir/src/game.cpp.i

CMakeFiles/app.dir/src/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arnav/courses/4/cg/ass1/src/game.cpp -o CMakeFiles/app.dir/src/game.cpp.s

CMakeFiles/app.dir/src/game_object.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/game_object.cpp.o: ../src/game_object.cpp
CMakeFiles/app.dir/src/game_object.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arnav/courses/4/cg/ass1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/app.dir/src/game_object.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/src/game_object.cpp.o -MF CMakeFiles/app.dir/src/game_object.cpp.o.d -o CMakeFiles/app.dir/src/game_object.cpp.o -c /home/arnav/courses/4/cg/ass1/src/game_object.cpp

CMakeFiles/app.dir/src/game_object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/game_object.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arnav/courses/4/cg/ass1/src/game_object.cpp > CMakeFiles/app.dir/src/game_object.cpp.i

CMakeFiles/app.dir/src/game_object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/game_object.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arnav/courses/4/cg/ass1/src/game_object.cpp -o CMakeFiles/app.dir/src/game_object.cpp.s

CMakeFiles/app.dir/src/main.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/app.dir/src/main.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arnav/courses/4/cg/ass1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/app.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/src/main.cpp.o -MF CMakeFiles/app.dir/src/main.cpp.o.d -o CMakeFiles/app.dir/src/main.cpp.o -c /home/arnav/courses/4/cg/ass1/src/main.cpp

CMakeFiles/app.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arnav/courses/4/cg/ass1/src/main.cpp > CMakeFiles/app.dir/src/main.cpp.i

CMakeFiles/app.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arnav/courses/4/cg/ass1/src/main.cpp -o CMakeFiles/app.dir/src/main.cpp.s

CMakeFiles/app.dir/src/resource_manager.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/resource_manager.cpp.o: ../src/resource_manager.cpp
CMakeFiles/app.dir/src/resource_manager.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arnav/courses/4/cg/ass1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/app.dir/src/resource_manager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/src/resource_manager.cpp.o -MF CMakeFiles/app.dir/src/resource_manager.cpp.o.d -o CMakeFiles/app.dir/src/resource_manager.cpp.o -c /home/arnav/courses/4/cg/ass1/src/resource_manager.cpp

CMakeFiles/app.dir/src/resource_manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/resource_manager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arnav/courses/4/cg/ass1/src/resource_manager.cpp > CMakeFiles/app.dir/src/resource_manager.cpp.i

CMakeFiles/app.dir/src/resource_manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/resource_manager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arnav/courses/4/cg/ass1/src/resource_manager.cpp -o CMakeFiles/app.dir/src/resource_manager.cpp.s

CMakeFiles/app.dir/src/shader.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/shader.cpp.o: ../src/shader.cpp
CMakeFiles/app.dir/src/shader.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arnav/courses/4/cg/ass1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/app.dir/src/shader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/src/shader.cpp.o -MF CMakeFiles/app.dir/src/shader.cpp.o.d -o CMakeFiles/app.dir/src/shader.cpp.o -c /home/arnav/courses/4/cg/ass1/src/shader.cpp

CMakeFiles/app.dir/src/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arnav/courses/4/cg/ass1/src/shader.cpp > CMakeFiles/app.dir/src/shader.cpp.i

CMakeFiles/app.dir/src/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arnav/courses/4/cg/ass1/src/shader.cpp -o CMakeFiles/app.dir/src/shader.cpp.s

CMakeFiles/app.dir/src/sprite_renderer.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/sprite_renderer.cpp.o: ../src/sprite_renderer.cpp
CMakeFiles/app.dir/src/sprite_renderer.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arnav/courses/4/cg/ass1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/app.dir/src/sprite_renderer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/src/sprite_renderer.cpp.o -MF CMakeFiles/app.dir/src/sprite_renderer.cpp.o.d -o CMakeFiles/app.dir/src/sprite_renderer.cpp.o -c /home/arnav/courses/4/cg/ass1/src/sprite_renderer.cpp

CMakeFiles/app.dir/src/sprite_renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/sprite_renderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arnav/courses/4/cg/ass1/src/sprite_renderer.cpp > CMakeFiles/app.dir/src/sprite_renderer.cpp.i

CMakeFiles/app.dir/src/sprite_renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/sprite_renderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arnav/courses/4/cg/ass1/src/sprite_renderer.cpp -o CMakeFiles/app.dir/src/sprite_renderer.cpp.s

CMakeFiles/app.dir/src/text_renderer.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/text_renderer.cpp.o: ../src/text_renderer.cpp
CMakeFiles/app.dir/src/text_renderer.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arnav/courses/4/cg/ass1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/app.dir/src/text_renderer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/src/text_renderer.cpp.o -MF CMakeFiles/app.dir/src/text_renderer.cpp.o.d -o CMakeFiles/app.dir/src/text_renderer.cpp.o -c /home/arnav/courses/4/cg/ass1/src/text_renderer.cpp

CMakeFiles/app.dir/src/text_renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/text_renderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arnav/courses/4/cg/ass1/src/text_renderer.cpp > CMakeFiles/app.dir/src/text_renderer.cpp.i

CMakeFiles/app.dir/src/text_renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/text_renderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arnav/courses/4/cg/ass1/src/text_renderer.cpp -o CMakeFiles/app.dir/src/text_renderer.cpp.s

CMakeFiles/app.dir/src/texture.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/texture.cpp.o: ../src/texture.cpp
CMakeFiles/app.dir/src/texture.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arnav/courses/4/cg/ass1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/app.dir/src/texture.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/src/texture.cpp.o -MF CMakeFiles/app.dir/src/texture.cpp.o.d -o CMakeFiles/app.dir/src/texture.cpp.o -c /home/arnav/courses/4/cg/ass1/src/texture.cpp

CMakeFiles/app.dir/src/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/texture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arnav/courses/4/cg/ass1/src/texture.cpp > CMakeFiles/app.dir/src/texture.cpp.i

CMakeFiles/app.dir/src/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/texture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arnav/courses/4/cg/ass1/src/texture.cpp -o CMakeFiles/app.dir/src/texture.cpp.s

# Object files for target app
app_OBJECTS = \
"CMakeFiles/app.dir/src/background.cpp.o" \
"CMakeFiles/app.dir/src/game.cpp.o" \
"CMakeFiles/app.dir/src/game_object.cpp.o" \
"CMakeFiles/app.dir/src/main.cpp.o" \
"CMakeFiles/app.dir/src/resource_manager.cpp.o" \
"CMakeFiles/app.dir/src/shader.cpp.o" \
"CMakeFiles/app.dir/src/sprite_renderer.cpp.o" \
"CMakeFiles/app.dir/src/text_renderer.cpp.o" \
"CMakeFiles/app.dir/src/texture.cpp.o"

# External object files for target app
app_EXTERNAL_OBJECTS =

app: CMakeFiles/app.dir/src/background.cpp.o
app: CMakeFiles/app.dir/src/game.cpp.o
app: CMakeFiles/app.dir/src/game_object.cpp.o
app: CMakeFiles/app.dir/src/main.cpp.o
app: CMakeFiles/app.dir/src/resource_manager.cpp.o
app: CMakeFiles/app.dir/src/shader.cpp.o
app: CMakeFiles/app.dir/src/sprite_renderer.cpp.o
app: CMakeFiles/app.dir/src/text_renderer.cpp.o
app: CMakeFiles/app.dir/src/texture.cpp.o
app: CMakeFiles/app.dir/build.make
app: libraries/glfw/src/libglfw3.a
app: libglad.a
app: /usr/lib/x86_64-linux-gnu/libfreetype.so
app: /usr/lib/x86_64-linux-gnu/librt.a
app: /usr/lib/x86_64-linux-gnu/libm.so
app: CMakeFiles/app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/arnav/courses/4/cg/ass1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable app"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/app.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/app.dir/build: app
.PHONY : CMakeFiles/app.dir/build

CMakeFiles/app.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/app.dir/cmake_clean.cmake
.PHONY : CMakeFiles/app.dir/clean

CMakeFiles/app.dir/depend:
	cd /home/arnav/courses/4/cg/ass1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arnav/courses/4/cg/ass1 /home/arnav/courses/4/cg/ass1 /home/arnav/courses/4/cg/ass1/build /home/arnav/courses/4/cg/ass1/build /home/arnav/courses/4/cg/ass1/build/CMakeFiles/app.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/app.dir/depend

