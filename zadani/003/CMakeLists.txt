cmake_minimum_required(VERSION 4.2.0)
project(MainProj CXX)

# enable C and C++ language
enable_language(C CXX)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
# Add sub-directories
add_subdirectory(zadani)
add_subdirectory(main)
