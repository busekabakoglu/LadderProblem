cmake_minimum_required(VERSION 2.8)
project(LadderProblem)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O2")
add_executable(LadderProblem main.cpp Station.cpp Station.h)