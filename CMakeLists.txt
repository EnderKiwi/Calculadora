cmake_minimum_required(VERSION 3.17)

project(Calculadora VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(utils)
add_subdirectory(math)

add_executable(Calculadora main.c Calculadora.c Calculadora.h license.c license.h)
target_link_libraries(Calculadora utils math)
