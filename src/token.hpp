//
// Created by bswenson3 on 5/28/22.
//
#pragma once

#include <token_type.hpp>

namespace xeon {

    class Token {
    public:
        Token(const char* location, TokenType type, const String& context) :
            m_location(location), m_type(type), m_context(context) {}

        [[nodiscard]] SourceLocation get_location() const { return SourceLocation::getFromPointer(m_location); }
        [[nodiscard]] TokenType get_type() const { return m_type; }
        [[nodiscard]] String get_context() const { return m_context; }

    private:
        const char* m_location;
        TokenType m_type = TokenType::invalid;
        String m_context;
    };

}
