cmake_minimum_required(VERSION 3.17)

project(maths VERSION 0.0.3)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED true)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../)

add_library(maths STATIC maths.c maths.h)
if(MSVC)
  target_compile_options(maths PRIVATE /W4 /WX)
else()
  target_compile_options(maths PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

target_link_libraries(maths utils)
