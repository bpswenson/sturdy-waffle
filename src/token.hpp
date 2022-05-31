//
// Created by bswenson3 on 5/28/22.
//
#pragma once

#include <token_type.hpp>

namespace xeon {

    class Token {
    public:
        Token(const char* location, TokenType type, uint32 size) :
            m_location(location), m_type(type), m_size(size) {}

        [[nodiscard]] SourceLocation get_location() const { return SourceLocation::getFromPointer(m_location); }
        [[nodiscard]] TokenType get_type() const { return m_type; }
        [[nodiscard]] uint32 get_size() const { return m_size; }

    private:
        const char* m_location;
        TokenType m_type = TokenType::invalid;
        uint32 m_size;
    };

}
