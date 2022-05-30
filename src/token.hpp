//
// Created by bswenson3 on 5/28/22.
//
#pragma once

#include <token_type.hpp>
#include <location.hpp>

namespace xeon {

    class Token {
    public:
        Token(const Location& location, TokenType type, const String& text) :
            m_location(location), m_type(type), m_text(text) {}

        [[nodiscard]] Location get_location() const { return m_location; }
        [[nodiscard]] TokenType get_type() const { return m_type; }
        [[nodiscard]] String get_text() const { return m_text; }

    private:
        Location m_location;
        TokenType m_type = TokenType::invalid;
        String m_text;

    };

}
