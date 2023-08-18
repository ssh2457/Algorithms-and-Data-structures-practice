cmake_minimum_required(VERSION 3.22.0)
project(week1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER "/usr/bin/clang++-14" CACHE STRING "C++ compiler" FORCE)
set(CMAKE_BUILD_TYPE "Debug")

add_executable(${PROJECT_NAME} test.cpp MyStack.cpp MyQueue.cpp)

target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Werror)
