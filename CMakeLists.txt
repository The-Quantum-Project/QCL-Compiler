#   Copyright (C) 2015 The Quantum Project
#
#      This program is free software: you can redistribute it and/or modify
#      it under the terms of the GNU General Public License as published by
#      the Free Software Foundation, either version 3 of the License, or
#      (at your option) any later version.
#
#      This program is distributed in the hope that it will be useful,
#      but WITHOUT ANY WARRANTY; without even the implied warranty of
#      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#      GNU General Public License for more details.
#
#      You should have received a copy of the GNU General Public License
#      along with this program.  If not, see <http://www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 3.0)
project(QCL_Compiler)

add_compile_options(-std=c++11)
set(SOURCE_FILES
        main.cpp
        Token.cpp
        Token.hpp
        TokenType.hpp
        stinc.hpp
        File.cpp
        File.hpp
        Compiler.cpp
        Compiler.hpp)

add_executable(QCL_Compiler ${SOURCE_FILES})
