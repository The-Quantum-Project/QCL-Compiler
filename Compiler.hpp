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

#include <string>
#include <vector>

/*
 * This is the Compiler class, here is where all the magic happens. To modify how this class functions and executes,
 * modify the compile arguments before passing them into the constructor. Once the arguments are set, the compiler will
 * take over. The first step in compiling is converting the quicel(QCL) code to (Q)byte code (QX). This is a certain
 * type of byte code generated and optimized for the Quantum Virtual Machine(QVM). Once the (Q)byte code has been
 * generated per input file into its corresponding output file, it needs to be linked. First the compiler will link it's
 * own code to the specified output file. The libraries are the last thing to be linked. Once everything is linked into
 * the designated output file specified by the arguments given, the code will be ready for execution. Code is executed
 * via the Quantum Virtual Machine(QVM). You will execute the QVM with your compiled program as an argument and it will
 * execute the file appropriately.
 */
class Compiler {
public:
    /*
     * This struct stores all of the required arguments of the compiler. These values should all ready be initialized
     * before being passed into the Compiler constructor. This is used to make the arguments easy to utilize during
     * compilation. These are the following Compile flags in the order that you see them in the struct.
     *
     * -I ... = Source/Input Files
     * -O .   = Output File Name
     * -L ... = Library Files
     * -MXR x = Max RAM for compilation
     * -MIR x = Min RAM for compilation
     */
    typedef struct {
        char* input;       //-I : Source Files (input)
        char* output;      //-O : Output File
        char* libraries;   //-L : Libraries
        unsigned long mxr; //-MXR : Max RAM (For compiling)
        unsigned long mir; //-MIR : MIN RAM (For compiling)
    } Arguments;

    Compiler(Arguments args);

    /*
     * Compile the QCL code down to our own version of byte code witch is designed and optimized to run on the Quantum
     * Virtual Machine. Our custom byte code extension is ".qx" and is similar to assembly. This function will take the
     * compiler's arguments and look specifiably at the input ("-I"). For each input file listed in the program
     * arguments, the compiler will make a corresponding compiled .qx file that contains the byte code we were talking
     * about previously.
     */
    void Compile();

    /*
     *
     */
    void Link();

protected:
    Arguments x_Arguments;
};

#endif //QCL_COMPILER_COMPILER_H
