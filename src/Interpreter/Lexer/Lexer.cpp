#include "Lexer.hpp"
#include "tokens.hpp"

#include "error.h"
#include <memory>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

namespace lexer {

struct Lexer::Impl {
    Impl(string file_in);
    ~Impl();
    bool next();
    void eat_whitespace();
    MyError tokenize();

    vector<Lexeme> m_tokens;
    string m_filename;
    ifstream m_read_file;
    int row;
    int col;
    char cur;
};

Lexer::Impl::Impl(string file_in)
    : m_filename(file_in)
    , row(1)
    , col(1)
{
    m_read_file.open(m_filename);
}

Lexer::Impl::~Impl() {
}

bool Lexer::Impl::next() {
    if (!m_read_file.get(cur)) {
        return false;
    }
    if (cur == '\n') {
        row++;
        col = 1;
        m_read_file.get(cur);
    }
    else {
        col++;
    }
    return true;
}

MyError Lexer::Impl::tokenize() {
    MyError err = ERR_NONE;
    while (next() && err == ERR_NONE) {
        eat_whitespace();
        // if char, identifier
        if (cur >= 'A' && cur <= 'z') {
            int start_row = row;
            int start_col = col;
            string val = "";
            val += cur;
            char next_char = m_read_file.peek();
            while ((next_char >= 'A' && next_char <= 'z') || next_char == '_') {
                next();
                val += cur;
                next_char = m_read_file.peek();
            }
            Lexeme new_lexeme;

            // check reserved words
            if (val == "if") new_lexeme.token = IF;
            else if (val == "for") new_lexeme.token = FOR;
            else if (val == "while") new_lexeme.token = WHILE;
            else if (val == "do") new_lexeme.token = DO;
            else if (val == "true" || val == "false") new_lexeme.token = BOOL;
            else new_lexeme.token = ID;

            new_lexeme.token = ID;
            new_lexeme.value = val;
            new_lexeme.row = start_row;
            new_lexeme.col = start_col;
            m_tokens.push_back(new_lexeme);
        }
        // if number, numeric type
        else if (cur >= '0' && cur <= '9') {
            int start_row = row;
            int start_col = col;
            bool is_float = false;
            string val = "";
            val += cur;
            char next_char = m_read_file.peek();
            while ((next_char >= '0' && next_char <= '9') || next_char == '.') {
                next();
                val += cur;
                if (cur == '.') {
                    if (!is_float) {
                        is_float = true;
                    }
                    else {
                        err = INVALID_TYPE;
                        break;
                    }
                }
                next_char = m_read_file.peek();
            }
            Lexeme num_lexeme;
            if (is_float) num_lexeme.token = FLOAT;
            else num_lexeme.token = INT;
            num_lexeme.value = val;
            num_lexeme.row = start_row;
            num_lexeme.col = start_col;
            m_tokens.push_back(num_lexeme);
        }
        else {
            // check special chars
            if (cur == '+') {
                
            }
            else if (cur == '-') {

            }
            else if (cur == '*') {

            }
            else if (cur == '/') {

            }
            else if (cur == '%') {

            }
            else if (cur == '"') {

            }
            else if (cur == '\'') {

            }
        }
    }
    return err;
}

void Lexer::Impl::eat_whitespace() {
    while (cur == ' ' || cur == '\n' || cur == '\t' || cur == '#') {
        if (cur == '#') {
            while (cur != '\n') {
                m_read_file.get(cur);
            }
            col = 1;
            row++;
        }
        next();
    }
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
