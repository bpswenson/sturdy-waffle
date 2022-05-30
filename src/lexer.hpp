//
// Created by bswenson3 on 5/28/22.
//

#pragma once

#include <token_type.hpp>

namespace xeon {

    // Provides interface that turns text buffer into stream of tokens.
    class Lexer {
    public:
        Lexer();
        TokenType get_next_token();


    private:
        void init_keyword_map();
        const char* m_buffer_start;
        const char* m_buffer_end;

        HashMap<String, TokenType> m_keywords;
        TokenType m_previous_type = TokenType::invalid;
        uint32 m_previous_id = 0;
    };

}
