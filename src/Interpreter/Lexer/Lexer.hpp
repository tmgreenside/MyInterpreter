#ifndef INTERPRETER_LEXER_LEXER_HPP
#define INTERPRETER_LEXER_LEXER_HPP

#include "tokens.hpp"
#include <iostream>
#include <vector>
#include <memory>

using namespace std;
namespace lexer {

struct Lexeme
{
    Token token;
    string value;
    int row;
    int col;
};

class Lexer {
public:
    Lexer(string file_in);
    ~Lexer();
    vector<Lexeme> get_tokens();
private:
    struct Impl;
    unique_ptr<Impl> m_p_impl;
};

} // end namespace Lexer

#endif
