#ifndef INTERPRETER_INTERPRETER_HPP
#define INTERPRETER_INTERPRETER_HPP

#include <memory>
#include <vector>
#include <iostream>

class Interpreter {
public:
    Interpreter(std::string file_in, std::vector<std::string> args_in);
    Interpreter(const Interpreter &interpreter) = delete;
    Interpreter operator=(const Interpreter &interpreter) = delete;
    ~Interpreter();
};

#endif
