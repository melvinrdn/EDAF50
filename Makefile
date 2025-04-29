# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic

# Directories
SRCDIR := src
OBJDIR := obj
BINDIR := bin
INCLUDES := -I$(SRCDIR)

# Source files
CLIENT_SRC := $(SRCDIR)/news_client.cc
SERVER_SRC := $(SRCDIR)/news_server.cc

# All .cc files under src
SRCS := $(wildcard $(SRCDIR)/*.cc)
OBJS := $(patsubst $(SRCDIR)/%.cc,$(OBJDIR)/%.o,$(SRCS))

# Main objects
CLIENT_OBJ := $(OBJDIR)/news_client.o
SERVER_OBJ := $(OBJDIR)/news_server.o

# Helper/library objects (everything except main)
LIB_OBJS := $(filter-out $(CLIENT_OBJ) $(SERVER_OBJ),$(OBJS))

.PHONY: all client server install clean

all: news_client news_server

# Build client
news_client: $(CLIENT_OBJ) $(LIB_OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@

# Build server
news_server: $(SERVER_OBJ) $(LIB_OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@

# Compile .cc to .o
$(OBJDIR)/%.o: $(SRCDIR)/%.cc
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Install binaries to bin/
install: all
	@mkdir -p $(BINDIR)
	cp news_client news_server $(BINDIR)/

# Clean build artifacts
clean:
	rm -rf $(OBJDIR) news_client news_server