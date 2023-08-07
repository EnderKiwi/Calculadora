cmake_minimum_required(VERSION 3.17)

project(utils VERSION 0.0.5)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED true)

add_library(utils STATIC utils.c utils.h terminal.c terminal.h except.c except.h)
if(MSVC)
  target_compile_options(utils PRIVATE /W4 /WX)
else()
  target_compile_options(utils PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()
