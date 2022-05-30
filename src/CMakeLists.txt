
project(XeonCompiler
        VERSION 0.0.1
        DESCRIPTION "Xeon Compiler")

set(SOURCE_FILES
        common.hpp
        lexer.cpp
        lexer.hpp
        location.hpp
        main.cpp
        token.hpp
        token_type.hpp
        version.conf.in
        version.hpp
        )

# include current source and build directories in include path
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(XEON_VERSION_STRING ${CMAKE_PROJECT_VERSION})
message(STATUS "Xeon Compiler Version ${XEON_VERSION_STRING}")
configure_file(
        version.conf.in
        ${CMAKE_BINARY_DIR}/version.conf
)

add_executable(xeon)
target_sources(xeon PRIVATE ${SOURCE_FILES})
target_link_libraries(xeon PRIVATE
        Boost::program_options
        llvm::core
        )
