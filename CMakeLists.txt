cmake_minimum_required(VERSION 3.17)

project(QuickMaths VERSION 0.0.6)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED true)

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

add_test(NAME QuickMathsAddTest COMMAND QuickMaths --return 16 + 8)
add_test(NAME QuickMathsSubTest COMMAND QuickMaths --return 128 - 64)
add_test(NAME QuickMathsMulTest COMMAND QuickMaths --return 2 * 2)
add_test(NAME QuickMathsDivTest COMMAND QuickMaths --return 16 / 4)
add_test(NAME QuickMathsModTest COMMAND QuickMaths --return 16 % 3)
add_test(NAME QuickMathsAddSubTest COMMAND QuickMaths --return 16 + 32 - 8)
add_test(NAME QuickMathsMulDivTest COMMAND QuickMaths --return 2 * 8 / 4)
#add_test(NAME QuickMathsOOOTest COMMAND QuickMaths --return 2 + 4 / 2) # TODO: Implement operator precedence (order of operations, AKA OOO)

set_property(TEST QuickMathsAddTest PROPERTY PASS_REGULAR_EXPRESSION "2")
set_property(TEST QuickMathsSubTest PROPERTY PASS_REGULAR_EXPRESSION "64")
set_property(TEST QuickMathsMulTest PROPERTY PASS_REGULAR_EXPRESSION "4")
set_property(TEST QuickMathsDivTest PROPERTY PASS_REGULAR_EXPRESSION "4")
set_property(TEST QuickMathsModTest PROPERTY PASS_REGULAR_EXPRESSION "1")
set_property(TEST QuickMathsAddSubTest PROPERTY PASS_REGULAR_EXPRESSION "40")
set_property(TEST QuickMathsMulDivTest PROPERTY PASS_REGULAR_EXPRESSION "4")
#set_property(TEST QuickMathsOOOTest PROPERTY PASS_REGULAR_EXPRESSION "2")
