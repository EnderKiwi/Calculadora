cmake_minimum_required(VERSION 3.17)

project(utils VERSION 0.0.2)

set(CMAKE_CXX_STANDARD 20)

add_library(utils STATIC utils.c utils.h terminal.c terminal.h)
