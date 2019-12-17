#ifndef INTERPRETER_LEXER_TOKENS_HPP
#define INTERPRETER_LEXER_TOKENS_HPP

enum Token {
    ID,
    INT,
    FLOAT,
    BOOL,
    STRING,
    CHAR,
    LBRACKET,
    RBRACKET,
    LPAREN,
    RPAREN,
    LCURLBRACKET,
    RCURLBRACKET,
    COMMA,
    NOT,
    BITAND,
    BITOR,
    AND,
    OR,
    PLUS,
    MINUS,
    MULT,
    DIV,
    MOD,
    IF,
    FOR,
    WHILE,
    DO,
    ASSIGN,
    EQUAL,
    NEQUAL,
    GT,
    GTE,
    LT,
    LTE
};

#endif
