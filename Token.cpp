#include "Token.h"

using namespace std;

Token::Token(TokenType tktype, string val) {
    type = tktype;
    value = val;
}

Token::~Token() {
}
