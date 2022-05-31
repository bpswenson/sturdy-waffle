//
// Created by bswenson3 on 5/28/22.
//
#pragma once

#include <common.hpp>


namespace xeon {
    enum class TokenType {
        invalid,
        kw_function,
        lparen,
        rparen,
        lsquare,
        rsquare,
        plus,
        minus,
        asterisk,
        divide,
        single_quote,
        double_quote,
        semicolon,
        eof
    };


}
