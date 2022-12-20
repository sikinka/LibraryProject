cmake_minimum_required(VERSION 3.23)
project(LibraryProject)

set(CMAKE_CXX_STANDARD 20)

add_executable(LibraryProject main.cpp Book.h Library.h Book.cpp Library.cpp)
