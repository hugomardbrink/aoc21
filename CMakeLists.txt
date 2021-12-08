cmake_minimum_required(VERSION 3.10)

# set the project name
project(AoC-2021)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
add_executable(01A "solutions/01A.cpp")
add_executable(01B "solutions/01B.cpp")
add_executable(02A "solutions/02A.cpp")
add_executable(02B "solutions/02B.cpp")
add_executable(03A "solutions/03A.cpp")
add_executable(03B "solutions/03B.cpp")