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
