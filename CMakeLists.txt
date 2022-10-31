cmake_minimum_required(VERSION 3.21)
project(snake44)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-lncurses")

add_executable(snake44 map.cpp snake.cpp mission.cpp)
