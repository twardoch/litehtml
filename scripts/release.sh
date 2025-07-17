#!/bin/bash
# Release script for litehtml
# this_file: scripts/release.sh

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"
BUILD_DIR="$PROJECT_ROOT/build"
RELEASE_DIR="$PROJECT_ROOT/release"

# Check if we're on a tagged commit
if ! git describe --exact-match --tags HEAD >/dev/null 2>&1; then
    echo "Error: Not on a tagged commit. Please create a git tag first."
    echo "Example: git tag v1.0.0 && git push origin v1.0.0"
    exit 1
fi

TAG=$(git describe --exact-match --tags HEAD)
echo "=== Creating release for tag: $TAG ==="
echo

# Clean and build
echo "Building release version..."
BUILD_TYPE=Release ENABLE_TESTS=ON "$SCRIPT_DIR/build.sh" clean

# Run tests
echo "Running tests..."
"$SCRIPT_DIR/test.sh"

# Create release directory
rm -rf "$RELEASE_DIR"
mkdir -p "$RELEASE_DIR"

# Install to release directory
echo "Installing to release directory..."
cd "$BUILD_DIR"
cmake --install . --prefix "$RELEASE_DIR"

# Create source archive
echo "Creating source archive..."
cd "$PROJECT_ROOT"
git archive --format=tar.gz --prefix="litehtml-$TAG/" HEAD > "$RELEASE_DIR/litehtml-$TAG-source.tar.gz"

# Create binary archive
echo "Creating binary archive..."
cd "$RELEASE_DIR"
tar -czf "litehtml-$TAG-$(uname -s)-$(uname -m).tar.gz" \
    --exclude="*.tar.gz" \
    --exclude="*.zip" \
    .

# Generate checksums
echo "Generating checksums..."
cd "$RELEASE_DIR"
sha256sum *.tar.gz > SHA256SUMS

echo "Release created successfully!"
echo "Release artifacts are in: $RELEASE_DIR"
echo
echo "Files created:"
ls -la "$RELEASE_DIR"
echo
echo "To upload to GitHub releases:"
echo "1. Go to https://github.com/litehtml/litehtml/releases"
echo "2. Create a new release for tag $TAG"
echo "3. Upload the files from $RELEASE_DIR"