cmake_minimum_required(VERSION 3.17)

project(maths VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)

add_library(maths STATIC maths.c maths.h)
