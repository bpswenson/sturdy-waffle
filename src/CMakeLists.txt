
project(XeonCompiler
        DESCRIPTION "Xeon Compiler")

set(XEON_VERSION_STRING "\"0.0.1\"")

# include current source and build directories in include path
set(CMAKE_INCLUDE_CURRENT_DIR ON)

message(STATUS "Xeon Compiler Version ${XEON_VERSION_STRING}")
configure_file(
        version.conf.in
        ${CMAKE_BINARY_DIR}/version.conf
)

add_library(xeon_lib)

target_include_directories(xeon_lib PUBLIC ${CMAKE_BINARY_DIR})

target_sources(xeon_lib PRIVATE
    lexer.cpp
    version.cpp
        )
target_sources(xeon_lib PUBLIC
        common.hpp
        lexer.cpp
        lexer.hpp
        token.hpp
        token_type.hpp
        version.conf.in
        version.hpp
        version.cpp
        ${CMAKE_BINARY_DIR}/version.conf
        )
target_link_libraries(xeon_lib PUBLIC
        llvm::core
        llvm::support
        )

add_executable(xeon)
target_sources(xeon PRIVATE main.cpp)
target_link_libraries(xeon PUBLIC
        xeon_lib
        )
