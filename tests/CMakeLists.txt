#in future can perhaps auto download https://github.com/catchorg/Catch2/blob/devel/docs/cmake-integration.md#top
# with fetch context and list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

find_package(Catch2 REQUIRED)

include(CTest)
include(Catch)

# smoke test
add_subdirectory( silly_test )
add_subdirectory( lexer_simple )
