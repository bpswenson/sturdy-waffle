//
// Created by bswenson3 on 5/29/22.
//
#include <string>

#include <catch2/catch.hpp>
#include <lexer.hpp>

using namespace xeon;

TEST_CASE("Lexer: Simple Int", "[Lexer]") {

    std::string test_int = "53";

    sptr<SourceManager> source_manager = std::make_shared<SourceManager>();

    source_manager->AddNewSourceBuffer(MemoryBuffer::getMemBuffer(test_int, "testIntBuffer"), SourceLocation());

    Lexer lex = Lexer(source_manager);

    Token tok = lex.get_next_token();

    REQUIRE(tok.get_type() == TokenType::integer_literal);
    REQUIRE(tok.get_context() == "53");

}