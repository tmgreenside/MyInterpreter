#include "Interpreter.hpp"
#include "Lexer/Lexer.hpp"
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

Interpreter::Interpreter(string file_in, vector<string> args_in) {
    shared_ptr<lexer::Lexer> p_lexer = make_shared<lexer::Lexer>(file_in);
}

Interpreter::~Interpreter()
{
}
