cmake_minimum_required(VERSION 3.10)
project(Moritat C)

set(CMAKE_C_STANDARD 11)

add_executable(moritat main.c simple/simple.c)
