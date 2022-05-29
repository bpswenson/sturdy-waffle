//
// Created by bswenson3 on 5/28/22.
//
#include <lexer.hpp>

namespace xeon {

    Lexer::Lexer() {

    }

    void Lexer::init_keyword_map() {
        m_keywords["func"] = TokenType::function;

    }

    TokenType Lexer::get_next_token() {

    }

}