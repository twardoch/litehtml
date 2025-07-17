# Tests for litehtml
cmake_minimum_required(VERSION 3.11)

find_package(GTest QUIET)
if(NOT GTest_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50f33f9142fd2db193c97c3d66aa73.zip
    )
    FetchContent_MakeAvailable(googletest)
endif()

# Test executable
add_executable(litehtml_tests
    test_main.cpp
    test_version.cpp
    test_css_parser.cpp
    test_css_selector.cpp
    test_document.cpp
    test_element.cpp
    test_render.cpp
    test_utils.cpp
)

target_link_libraries(litehtml_tests
    PRIVATE
    gtest_main
    litehtml
)

target_include_directories(litehtml_tests
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../containers/test
)

include(GoogleTest)
gtest_discover_tests(litehtml_tests)

# Add test resources
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR})