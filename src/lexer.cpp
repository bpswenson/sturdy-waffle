//
// Created by bswenson3 on 5/28/22.
//
#include <lexer.hpp>
#include <regex>

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

    Pair<bool, Token> Lexer::match_regex(const String& regex, TokenType type, StringView& segment) {
        std::regex re(regex);
        // ick temp string since regex doesn't seem to work with string views
        // https://en.cppreference.com/w/cpp/regex/regex_iterator
        String s = {segment.begin(), segment.end()};
        auto iterator = std::sregex_iterator(s.begin(), s.end(), re);
        // if I found a match
        if(iterator != std::sregex_iterator()) {
            String context = static_cast<String>((*iterator).str());

            return { true,  Token(m_current_location, type, context)};
        }
        else {
            return { false, Token(m_current_location, TokenType::invalid, "")};
        }
    }

    Token Lexer::get_next_token() {
        // eat whitespace
        while(*m_current_location && is_whitespace(*m_current_location)) {
            ++m_current_location;
        }
        // check for end of file
        if(!*m_current_location) {
            return Token(m_current_location, TokenType::end_of_file, "");
        }

        // find next whitespace character after this char
        // again making the likely horrible assumption there's a '\n' prior to eof
        auto end_segment = m_current_location + 1;
        while(!is_whitespace(*end_segment)) {
            end_segment++;
        }

        StringView segment = StringView(m_current_location, end_segment - m_current_location);

        auto match_float = match_regex("^[0-9]+\\.[0-9]+", TokenType::float_literal, segment);

        if(match_float.first) {
            // woo that worked, add the length of the returned context to m_current_location and return the token
        }

        auto match_int = match_regex("^[0-9]+", TokenType::integer_literal, segment);

        if(match_int.first) {
            // woo that worked, add the length of the returned context to m_current_location and return the token
        }

        return Token(m_current_location, TokenType::invalid, "");

    }

}