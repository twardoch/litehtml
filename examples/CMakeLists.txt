# Examples for litehtml
cmake_minimum_required(VERSION 3.11)

# Basic usage example
add_executable(basic_usage basic_usage.cpp)
target_link_libraries(basic_usage litehtml)

# Copy example to build directory for easy testing
add_custom_target(run_basic_usage
    COMMAND basic_usage
    DEPENDS basic_usage
    COMMENT "Running basic usage example"
)