//
// Created by bswenson3 on 5/28/22.
//

#pragma once

#include <token_type.hpp>
#include <token.hpp>

namespace xeon {

    // Provides interface that turns text buffer into stream of tokens.

    // TODO:  Make sure there's a '\n' at the end of the file
    //        Not going to be looking for eof in the middle of a line
    class Lexer {
    public:
        explicit Lexer(sptr<SourceManager>& sm);
        Token get_next_token();

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

        inline static bool is_alpha(char ch) {
            return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
        }

        // variable names can start with an alpha or underscore
        inline static bool is_identifier_start(char ch) {
            return is_ascii(ch) && (ch == '_' || is_alpha(ch));
        }

        // after the first character can use numerics in variable names
        inline static bool is_identifier_body(char ch) {
            return is_identifier_start(ch) || is_digit(ch);
        }

        Pair<bool, Token> match_regex(const String& regex, TokenType type, StringView& segment);

        sptr<SourceManager> m_source_manager;
        HashMap<String, TokenType> m_keywords;
        TokenType m_previous_type = TokenType::invalid;
        const char* m_current_location;
        StringView m_current_buffer;
        uint32 m_buffer_id;
    };
}
