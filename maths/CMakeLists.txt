cmake_minimum_required(VERSION 3.17)

project(maths VERSION 0.0.2)

set(CMAKE_CXX_STANDARD 20)

add_library(maths STATIC maths.c maths.h)
if(MSVC)
  target_compile_options(maths PRIVATE /W4 /WX)
else()
  target_compile_options(maths PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()
