cmake_minimum_required(VERSION 3.17)

project(utils VERSION 0.0.4)

set(CMAKE_CXX_STANDARD 20)

add_library(utils STATIC utils.c utils.h terminal.c terminal.h)
if(MSVC)
  target_compile_options(utils PRIVATE /W4 /WX)
else()
  target_compile_options(utils PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()
