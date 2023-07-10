cmake_minimum_required(VERSION 3.17)

project(Calculadora VERSION 0.0.2)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(utils)
add_subdirectory(math)

add_executable(Calculadora main.c Calculadora.c Calculadora.h license.c license.h)
target_link_libraries(Calculadora utils math)

add_test(NAME CalculadoraTest COMMAND Calculadora)
add_test(NAME CalculadoraTestHelp COMMAND Calculadora --help)
add_test(NAME CalculadoraTestVersion COMMAND Calculadora --version)
add_test(NAME CalculadoraTestLicense COMMAND Calculadora --license)
