#include "Interpreter.hpp"
#include "Tokenizer.hpp"
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

struct Interpreter::Impl {
    Impl(string file_in, vector<string> );
    ~Impl();

    string m_main_file;
    vector<string> m_args;
};

Interpreter::Impl::Impl(string file_in, vector<string> args_in)
    : m_main_file(file_in)
    , m_args(args_in)
{
}

Interpreter::Impl::~Impl() {
}

Interpreter::Interpreter(string file_in, vector<string> args_in)
    : m_p_impl(make_unique<Interpreter::Impl>(file_in, args_in))
{
    cout << "Constructor called" << endl;
}

Interpreter::~Interpreter() {
}
