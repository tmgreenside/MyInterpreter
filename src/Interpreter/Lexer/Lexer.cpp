#include "Lexer.hpp"
#include "tokens.hpp"

#include <memory>
#include <ifstream>

using namespace std;

namespace lexer {

struct Lexer::Impl {
    Impl(string file_in);
    ~Impl();
    void tokenize();

    vector<Lexeme> m_tokens;
    string m_filename;
    int row;
    int col;
};

Lexer::Impl::Impl(string file_in)
    : m_filename(file_in)
    , row(1)
    , col(1)
{
}

Lexer::Impl::~Impl() {
}

void Lexer::Impl::tokenize() {

}

Lexer::Lexer(std::string file_in)
    : m_p_impl(make_unique<Lexer::Impl>(file_in))
{
    m_p_impl->tokenize();
}

Lexer::~Lexer() {
}

vector<Lexeme> Lexer::get_tokens() {
    return m_p_impl->m_tokens;
}

} // end namespace Lexer
