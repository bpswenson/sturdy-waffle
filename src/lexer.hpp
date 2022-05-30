//
// Created by bswenson3 on 5/28/22.
//

#pragma once

#include <token_type.hpp>

namespace xeon {

    // Provides interface that turns text buffer into stream of tokens.
    class Lexer {
    public:
        explicit Lexer(const MemoryBuffer& input_file);
        TokenType get_next_token();


    private:
        void init_keyword_map();
        inline static bool is_ascii(char ch) {
            return static_cast<uchar>(ch) <= 127;
        }

        inline static bool is_whitespace(char ch) {
            return is_ascii(ch) && (ch == '\r' || ch == '\n' ||
                                    ch == ' '  || ch == '\t' ||
                                    ch == '\f' || ch == '\v'
                                    );
        }

        inline static bool is_digit(char ch) {
            return is_ascii(ch) && (ch >= '0' && ch <= '9');
        }

        // variable names can start with an alpha or underscore
        inline static bool is_identifier_start(char ch) {
            return is_ascii(ch) && (ch == '_' || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
        }

        // after the first character can use numerics in variable names
        inline static bool is_identifier_body(char ch) {
            return is_identifier_start(ch) || is_digit(ch);
        }



        const char* m_buffer_start;
        const char* m_buffer_end;
        const char* m_buffer_ptr;


        HashMap<String, TokenType> m_keywords;
        TokenType m_previous_type = TokenType::invalid;
        uint32 m_previous_id = 0;
    };

}
