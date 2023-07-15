cmake_minimum_required(VERSION 3.17)

project(QuickMaths VERSION 0.0.4)

set(CMAKE_CXX_STANDARD 20)

enable_testing()

add_subdirectory(utils)
add_subdirectory(maths)

add_executable(QuickMaths main.c QuickMaths.c QuickMaths.h license.c license.h)
target_link_libraries(QuickMaths utils maths)

if(MSVC)
  target_compile_options(QuickMaths PRIVATE /W4 /WX)
else()
  target_compile_options(QuickMaths PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

add_test(NAME QuickMathsTest COMMAND QuickMaths)
