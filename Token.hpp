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

#ifndef QCL_COMPILER_TOKEN_H
#define QCL_COMPILER_TOKEN_H

#include "TokenType.hpp"
#include <string>

using namespace std;

class Token {
public:
    string value;
    TokenType type;

    Token(TokenType tktype, string val);

    ~Token();
};

#endif //QCL_COMPILER_TOKEN_H
