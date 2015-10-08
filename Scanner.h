#ifndef QCL_COMPILER_SCANNER_H
#define QCL_COMPILER_SCANNER_H

#include <list>
#include "Token.h"

using namespace std;

class Scanner {
public:
    Scanner();

    ~Scanner();

    list<Token> Scan(string src);

private:
    string source;
    list<Token> tokens;
    int pos;
    int linenum;
    int linepos;

    Token ScanIdentifier();

    Token ScanString();
};

#endif //QCL_COMPILER_SCANNER_H
