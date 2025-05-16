cmake_minimum_required(VERSION 3.10)
project(find_square_wrapper)

set(CMAKE_CXX_STANDARD 11)

# Find interpreter and development files for Python
find_package(Python3 REQUIRED COMPONENTS Interpreter Development)

# Include Python directories and the current project directory
include_directories(${Python3_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Add find.h folder
include_directories(..)  

# Compile shared library called '_find_square' with these source files
add_library(_find_square MODULE
    ../find.cpp
    find_square_wrap.cxx
)

# Set the output library name to '_find_square'
set_target_properties(_find_square PROPERTIES
    PREFIX "" # No prefix
    SUFFIX ".so"
)

# Bind the shared library to Python
target_link_libraries(_find_square ${Python3_LIBRARIES})
