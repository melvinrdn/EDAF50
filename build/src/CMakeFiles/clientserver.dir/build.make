# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/build

# Include any dependencies generated for this target.
include src/CMakeFiles/clientserver.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/clientserver.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/clientserver.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/clientserver.dir/flags.make

src/CMakeFiles/clientserver.dir/codegen:
.PHONY : src/CMakeFiles/clientserver.dir/codegen

src/CMakeFiles/clientserver.dir/article.cc.o: src/CMakeFiles/clientserver.dir/flags.make
src/CMakeFiles/clientserver.dir/article.cc.o: /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/src/article.cc
src/CMakeFiles/clientserver.dir/article.cc.o: src/CMakeFiles/clientserver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/clientserver.dir/article.cc.o"
	cd /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/clientserver.dir/article.cc.o -MF CMakeFiles/clientserver.dir/article.cc.o.d -o CMakeFiles/clientserver.dir/article.cc.o -c /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/src/article.cc

src/CMakeFiles/clientserver.dir/article.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/clientserver.dir/article.cc.i"
	cd /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/src/article.cc > CMakeFiles/clientserver.dir/article.cc.i

src/CMakeFiles/clientserver.dir/article.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/clientserver.dir/article.cc.s"
	cd /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/src/article.cc -o CMakeFiles/clientserver.dir/article.cc.s

src/CMakeFiles/clientserver.dir/connection.cc.o: src/CMakeFiles/clientserver.dir/flags.make
src/CMakeFiles/clientserver.dir/connection.cc.o: /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/src/connection.cc
src/CMakeFiles/clientserver.dir/connection.cc.o: src/CMakeFiles/clientserver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/clientserver.dir/connection.cc.o"
	cd /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/clientserver.dir/connection.cc.o -MF CMakeFiles/clientserver.dir/connection.cc.o.d -o CMakeFiles/clientserver.dir/connection.cc.o -c /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/src/connection.cc

src/CMakeFiles/clientserver.dir/connection.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/clientserver.dir/connection.cc.i"
	cd /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/src/connection.cc > CMakeFiles/clientserver.dir/connection.cc.i

src/CMakeFiles/clientserver.dir/connection.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/clientserver.dir/connection.cc.s"
	cd /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/src/connection.cc -o CMakeFiles/clientserver.dir/connection.cc.s

src/CMakeFiles/clientserver.dir/memory_database.cc.o: src/CMakeFiles/clientserver.dir/flags.make
src/CMakeFiles/clientserver.dir/memory_database.cc.o: /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/src/memory_database.cc
src/CMakeFiles/clientserver.dir/memory_database.cc.o: src/CMakeFiles/clientserver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/clientserver.dir/memory_database.cc.o"
	cd /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/clientserver.dir/memory_database.cc.o -MF CMakeFiles/clientserver.dir/memory_database.cc.o.d -o CMakeFiles/clientserver.dir/memory_database.cc.o -c /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/src/memory_database.cc

src/CMakeFiles/clientserver.dir/memory_database.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/clientserver.dir/memory_database.cc.i"
	cd /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/src/memory_database.cc > CMakeFiles/clientserver.dir/memory_database.cc.i

src/CMakeFiles/clientserver.dir/memory_database.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/clientserver.dir/memory_database.cc.s"
	cd /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/src/memory_database.cc -o CMakeFiles/clientserver.dir/memory_database.cc.s

src/CMakeFiles/clientserver.dir/messagehandler.cc.o: src/CMakeFiles/clientserver.dir/flags.make
src/CMakeFiles/clientserver.dir/messagehandler.cc.o: /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/src/messagehandler.cc
src/CMakeFiles/clientserver.dir/messagehandler.cc.o: src/CMakeFiles/clientserver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/clientserver.dir/messagehandler.cc.o"
	cd /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/clientserver.dir/messagehandler.cc.o -MF CMakeFiles/clientserver.dir/messagehandler.cc.o.d -o CMakeFiles/clientserver.dir/messagehandler.cc.o -c /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/src/messagehandler.cc

src/CMakeFiles/clientserver.dir/messagehandler.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/clientserver.dir/messagehandler.cc.i"
	cd /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/src/messagehandler.cc > CMakeFiles/clientserver.dir/messagehandler.cc.i

src/CMakeFiles/clientserver.dir/messagehandler.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/clientserver.dir/messagehandler.cc.s"
	cd /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/src/messagehandler.cc -o CMakeFiles/clientserver.dir/messagehandler.cc.s

src/CMakeFiles/clientserver.dir/newsgroup.cc.o: src/CMakeFiles/clientserver.dir/flags.make
src/CMakeFiles/clientserver.dir/newsgroup.cc.o: /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/src/newsgroup.cc
src/CMakeFiles/clientserver.dir/newsgroup.cc.o: src/CMakeFiles/clientserver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/clientserver.dir/newsgroup.cc.o"
	cd /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/clientserver.dir/newsgroup.cc.o -MF CMakeFiles/clientserver.dir/newsgroup.cc.o.d -o CMakeFiles/clientserver.dir/newsgroup.cc.o -c /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/src/newsgroup.cc

src/CMakeFiles/clientserver.dir/newsgroup.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/clientserver.dir/newsgroup.cc.i"
	cd /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/src/newsgroup.cc > CMakeFiles/clientserver.dir/newsgroup.cc.i

src/CMakeFiles/clientserver.dir/newsgroup.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/clientserver.dir/newsgroup.cc.s"
	cd /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/src/newsgroup.cc -o CMakeFiles/clientserver.dir/newsgroup.cc.s

src/CMakeFiles/clientserver.dir/server.cc.o: src/CMakeFiles/clientserver.dir/flags.make
src/CMakeFiles/clientserver.dir/server.cc.o: /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/src/server.cc
src/CMakeFiles/clientserver.dir/server.cc.o: src/CMakeFiles/clientserver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/clientserver.dir/server.cc.o"
	cd /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/clientserver.dir/server.cc.o -MF CMakeFiles/clientserver.dir/server.cc.o.d -o CMakeFiles/clientserver.dir/server.cc.o -c /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/src/server.cc

src/CMakeFiles/clientserver.dir/server.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/clientserver.dir/server.cc.i"
	cd /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/src/server.cc > CMakeFiles/clientserver.dir/server.cc.i

src/CMakeFiles/clientserver.dir/server.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/clientserver.dir/server.cc.s"
	cd /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/src/server.cc -o CMakeFiles/clientserver.dir/server.cc.s

# Object files for target clientserver
clientserver_OBJECTS = \
"CMakeFiles/clientserver.dir/article.cc.o" \
"CMakeFiles/clientserver.dir/connection.cc.o" \
"CMakeFiles/clientserver.dir/memory_database.cc.o" \
"CMakeFiles/clientserver.dir/messagehandler.cc.o" \
"CMakeFiles/clientserver.dir/newsgroup.cc.o" \
"CMakeFiles/clientserver.dir/server.cc.o"

# External object files for target clientserver
clientserver_EXTERNAL_OBJECTS =

src/libclientserver.a: src/CMakeFiles/clientserver.dir/article.cc.o
src/libclientserver.a: src/CMakeFiles/clientserver.dir/connection.cc.o
src/libclientserver.a: src/CMakeFiles/clientserver.dir/memory_database.cc.o
src/libclientserver.a: src/CMakeFiles/clientserver.dir/messagehandler.cc.o
src/libclientserver.a: src/CMakeFiles/clientserver.dir/newsgroup.cc.o
src/libclientserver.a: src/CMakeFiles/clientserver.dir/server.cc.o
src/libclientserver.a: src/CMakeFiles/clientserver.dir/build.make
src/libclientserver.a: src/CMakeFiles/clientserver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library libclientserver.a"
	cd /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/build/src && $(CMAKE_COMMAND) -P CMakeFiles/clientserver.dir/cmake_clean_target.cmake
	cd /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/clientserver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/clientserver.dir/build: src/libclientserver.a
.PHONY : src/CMakeFiles/clientserver.dir/build

src/CMakeFiles/clientserver.dir/clean:
	cd /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/build/src && $(CMAKE_COMMAND) -P CMakeFiles/clientserver.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/clientserver.dir/clean

src/CMakeFiles/clientserver.dir/depend:
	cd /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50 /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/src /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/build /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/build/src /Users/mohamedalbakkour/Documents/C++/project/git/EDAF50/build/src/CMakeFiles/clientserver.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/clientserver.dir/depend

