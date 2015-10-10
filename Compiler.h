/*
 *   Copyright (C) 2015 The Quantum Project
 *
 *      This program is free software: you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation, either version 3 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef QCL_COMPILER_COMPILER_H
#define QCL_COMPILER_COMPILER_H

class Compiler {
public:
    typedef struct {
        char* input;       //-I : Source Files (input)
        char* output;      //-O : Output File
        char* libraries;   //-L : Libraries
        unsigned long mxr; //-MXR : Max RAM (For compiling)
        unsigned long mir; //-MIR : MIN RAM (For compiling)
    } Arguments;

    Compiler(Arguments args);

};

#endif //QCL_COMPILER_COMPILER_H
