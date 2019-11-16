#ifndef INTERPRETER_INTERPRETER_HPP
#define INTERPRETER_INTERPRETER_HPP

#include <memory>
#include <iostream>

class Interpreter {
public: 
    Interpreter(std::string file_in);
    ~Interpreter();
private:
    struct Impl;
    std::unique_ptr<Impl> m_p_impl;
};

#endif