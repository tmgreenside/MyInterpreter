#include "Interpreter.hpp"
#include <iostream>
#include <memory>

using namespace std;

struct Interpreter::Impl {
    Impl(std::string file_in);
    ~Impl();

    std::string m_main_file;
};

Interpreter::Impl::Impl(std::string file_in)
{
	m_main_file = file_in;
}

Interpreter::Impl::~Impl() {
}

Interpreter::Interpreter(std::string file_in)
{
    m_p_impl = make_unique<Interpreter::Impl>(file_in);
    cout << "Constructor called" << endl;
}

Interpreter::~Interpreter() {

}
