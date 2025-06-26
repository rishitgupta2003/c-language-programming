cmake_minimum_required(VERSION 3.31)
project(IntC C)

set(CMAKE_C_STANDARD 90)

add_executable(IntC
        Practice/other.c
        Practice/other.h
        Practice/main.c
        Practice/listnode.h
        Practice/listnode.c)
