#ifndef QCL_COMPILER_TOKEN_H
#define QCL_COMPILER_TOKEN_H

#include "TokenType.h"
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
