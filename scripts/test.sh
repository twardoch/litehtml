#!/bin/bash
# Test script for litehtml
# this_file: scripts/test.sh

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"
BUILD_DIR="$PROJECT_ROOT/build"

echo "=== Testing litehtml ==="
echo "Project root: $PROJECT_ROOT"
echo "Build directory: $BUILD_DIR"
echo

# Build first if not already built
if [[ ! -d "$BUILD_DIR" ]]; then
    echo "Build directory not found, building first..."
    ENABLE_TESTS=ON "$SCRIPT_DIR/build.sh"
fi

cd "$BUILD_DIR"

# Run unit tests
echo "Running unit tests..."
if [[ -f "tests/litehtml_tests" ]]; then
    echo "Running litehtml unit tests..."
    ./tests/litehtml_tests --gtest_output=xml:test_results.xml
else
    echo "Unit tests not found, skipping..."
fi

# Run integration tests (if litehtml-tests are available)
if [[ -d "litehtml-tests-build" ]]; then
    echo "Running integration tests..."
    cd litehtml-tests-build
    ctest -C Release --output-on-failure --parallel $(nproc)
else
    echo "Integration tests not found, building with integration tests..."
    cd "$PROJECT_ROOT"
    mkdir -p build-integration
    cd build-integration
    cmake .. -DLITEHTML_BUILD_TESTING=ON -DCMAKE_BUILD_TYPE=Release
    cmake --build . --config Release --parallel $(nproc)
    
    if [[ -d "litehtml-tests-build" ]]; then
        echo "Running integration tests..."
        cd litehtml-tests-build
        ctest -C Release --output-on-failure --parallel $(nproc)
    fi
fi

echo "Tests completed successfully!"