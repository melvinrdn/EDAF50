# message(STATUS "${MSG_CMAKE_SUMMARY}")
cmake_minimum_required(VERSION 3.14)
project(EDAF50 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Wold-style-cast")

# Include headers globally
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add subdirectories
add_subdirectory(src)
add_subdirectory(app)
