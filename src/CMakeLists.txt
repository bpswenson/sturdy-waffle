
project(XeonCompiler
        VERSION 0.0.1
        DESCRIPTION "Xeon Compiler")

set(SOURCE_FILES
        common.hpp
        file.cpp
        file.hpp
        lexer.cpp
        lexer.hpp
        main.cpp
        token.hpp
        token_type.hpp
        )

# include current source and build directories in include path
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(xeon)
target_sources(xeon PRIVATE ${SOURCE_FILES})
target_link_libraries(xeon PRIVATE
        Boost::program_options
        llvm::core
        )
