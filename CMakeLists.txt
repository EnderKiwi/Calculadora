cmake_minimum_required(VERSION 3.17)

project(QuickMaths VERSION 0.0.3)

set(CMAKE_CXX_STANDARD 20)

enable_testing()

add_subdirectory(utils)
add_subdirectory(maths)

add_executable(QuickMaths main.c QuickMaths.c QuickMaths.h license.c license.h)
target_link_libraries(QuickMaths utils maths)

add_test(NAME QuickMathsTest COMMAND QuickMaths)
