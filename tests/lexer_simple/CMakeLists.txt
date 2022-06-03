add_executable(lexer_simple)
target_sources(lexer_simple PRIVATE lexer_simple.cpp)
target_include_directories(lexer_simple PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(lexer_simple PRIVATE Catch2::Catch2WithMain
        xeon_lib
        llvm::core
        llvm::support
        )
catch_discover_tests(lexer_simple)