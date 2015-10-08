cmake_minimum_required(VERSION 3.3)
project(QCL_Compiler)

add_compile_options(-std=c++11)
set(SOURCE_FILES main.cpp Token.cpp Token.h TokenType.h stinc.h)

add_executable(QCL_Compiler ${SOURCE_FILES})