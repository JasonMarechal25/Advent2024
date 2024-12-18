cmake_minimum_required(VERSION 3.28)
project(Advent2024)

set(CMAKE_CXX_STANDARD 20)

add_executable(Advent2024 main.cpp
        day01.h
)

find_package(Boost REQUIRED COMPONENTS algorithm)
target_link_libraries(Advent2024 Boost::algorithm)