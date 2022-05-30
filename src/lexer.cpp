//
// Created by bswenson3 on 5/28/22.
//
#include <lexer.hpp>

namespace xeon {

    Lexer::Lexer(const MemoryBuffer& input_file) :
            m_buffer_start(input_file.getBufferStart()),
            m_buffer_end(input_file.getBufferEnd()),
            m_buffer_ptr(input_file.getBufferStart())
    {
        init_keyword_map();
    }

    void Lexer::init_keyword_map() {
        m_keywords["func"] = TokenType::function;

    }

    Token Lexer::get_next_token() {

    }

}