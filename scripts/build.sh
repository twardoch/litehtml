#!/bin/bash
# Build script for litehtml
# this_file: scripts/build.sh

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"
BUILD_DIR="$PROJECT_ROOT/build"
BUILD_TYPE="${BUILD_TYPE:-Release}"
ENABLE_TESTS="${ENABLE_TESTS:-ON}"
ENABLE_EXAMPLES="${ENABLE_EXAMPLES:-OFF}"

echo "=== Building litehtml ==="
echo "Project root: $PROJECT_ROOT"
echo "Build directory: $BUILD_DIR"
echo "Build type: $BUILD_TYPE"
echo "Enable tests: $ENABLE_TESTS"
echo "Enable examples: $ENABLE_EXAMPLES"
echo

# Clean build directory if requested
if [[ "$1" == "clean" ]]; then
    echo "Cleaning build directory..."
    rm -rf "$BUILD_DIR"
fi

# Create build directory
mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

# Configure CMake
echo "Configuring CMake..."
cmake .. \
    -DCMAKE_BUILD_TYPE="$BUILD_TYPE" \
    -DLITEHTML_BUILD_TESTING="$ENABLE_TESTS" \
    -DCMAKE_INSTALL_PREFIX="$BUILD_DIR/install" \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

# Build
echo "Building..."
cmake --build . --config "$BUILD_TYPE" --parallel $(nproc)

echo "Build completed successfully!"
echo "Build artifacts are in: $BUILD_DIR"