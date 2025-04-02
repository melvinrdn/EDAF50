# Define the compiler and linker.
CXX = g++
CC  = $(CXX)

# Dependency generation flags for .d files.
DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

# Preprocessor, compiler, and linker flags.
# -I../include tells the compiler to look for headers in the EDAF50/include directory.
CPPFLAGS = -I../include
CXXFLAGS = -O2 -Wall -Wextra -pedantic-errors -Wold-style-cast -std=c++11 -g $(DEPFLAGS)
LDFLAGS = -g

# Source files: test file is in the current directory and implementation is in ../src.
# Note: Make sure test_newsgroup.cc includes "newsgroup.h" only.
SRCS = test_newsgroup.cc ../src/newsgroup.cc
OBJS = $(SRCS:.cc=.o)

# Name of the test executable.
TARGET = test_newsgroup

# Default target: build the test executable.
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS)

# Pattern rule to build object files from .cc files.
%.o: %.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

# Clean up generated files.
clean:
	-rm -f $(OBJS) $(TARGET) $(SRCS:.cc=.d)

.PHONY: all clean

# Include dependency files.
-include $(SRCS:.cc=.d)
