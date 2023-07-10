cmake_minimum_required(VERSION 3.17)

project(Calculadora VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(util)
add_subdirectory(math)

add_executable(Calculadora main.c Calculadora.c Calculadora.h)
target_link_libraries(Calculadora util math)
