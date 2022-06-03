
add_executable(smoke_test)
target_sources(smoke_test PRIVATE silly_test.cpp)
target_link_libraries(smoke_test PRIVATE Catch2::Catch2WithMain)
catch_discover_tests(smoke_test)