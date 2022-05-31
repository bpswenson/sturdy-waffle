//
// Created by bswenson3 on 5/28/22.
//
#include <lexer.hpp>

namespace xeon {

    Lexer::Lexer(sptr<SourceManager>& sm) :
        m_source_manager(sm)
    {
        init_keyword_map();

        m_buffer_id = m_source_manager->getMainFileID();
        m_current_buffer = m_source_manager->getMemoryBuffer(m_buffer_id)->getBuffer();
        m_current_location = m_current_buffer.begin();
    }

    void Lexer::init_keyword_map() {
        m_keywords["func"] = TokenType::kw_function;

    }

    Token Lexer::parse_identifier() {
        assert(false || "Not implemented");
        return Token {m_current_location, TokenType::invalid, 0};
    }

    Token Lexer::parse_number() {
        assert(false || "Not implemented");
        return Token {m_current_location, TokenType::invalid, 0};
    }

    Token Lexer::parse_string() {
        assert(false || "Not implemented");
        return Token {m_current_location, TokenType::invalid, 0};
    }
    Token Lexer::parse_word() {
        assert(false || "Not implemented");
        return Token {m_current_location, TokenType::invalid, 0};
    }

    Token Lexer::get_next_token() {
        // eat whitespace
        while(*m_current_location && is_whitespace(*m_current_location)) {
            ++m_current_location;
        }
        // check for end of file
        if(!*m_current_location) {
            return Token(m_current_location, TokenType::eof, 0);
        }
        else if (is_digit(*m_current_location)) {
            return parse_number();
        }
        else if (*m_current_location == '"' || *m_current_location == '\'') {
            return parse_string();
        }
        else if (is_alpha(*m_current_location)) {
            return parse_word();
        }
        // else if is_operator (could be one char '+' or two char '==')
        //   return parse_operator();

        return Token(m_current_location, TokenType::invalid, 0);

    }

}