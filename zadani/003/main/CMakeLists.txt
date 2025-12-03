cmake_minimum_required(VERSION 4.2.0)
project(main CXX)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
add_executable(main
  main.c
)
