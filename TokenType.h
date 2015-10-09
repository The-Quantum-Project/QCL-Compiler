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

#ifndef QCL_COMPILER_TOKENTYPE_H
#define QCL_COMPILER_TOKENTYPE_H

#include <iosfwd>

enum class TokenType {
    Identifier = 1,
    Double = 2,
    String = 2,
    LineTerminator = 4,
    OpeningBracket = 4,
    ClosingBracket = 4,
    OpeningSquareBracket = 4,
    ClosingSquareBracket = 4,
    OpeningParen = 8,
    ClosingParen = 8,
    BinOp = 16,
    UnOp = 16,
    CompOp = 16,
    AssignOp = 16,
    Comma = 16

};


#endif //QCL_COMPILER_TOKENTYPE_H
