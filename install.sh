#!/bin/bash
# Installation script for litehtml
# this_file: install.sh

set -e

VERSION="latest"
INSTALL_DIR="/usr/local"
PLATFORM="$(uname -s)-$(uname -m)"

# Parse command line arguments
while [[ $# -gt 0 ]]; do
    case $1 in
        --version)
            VERSION="$2"
            shift 2
            ;;
        --prefix)
            INSTALL_DIR="$2"
            shift 2
            ;;
        --help)
            echo "Usage: $0 [options]"
            echo "Options:"
            echo "  --version VERSION   Specify version to install (default: latest)"
            echo "  --prefix PREFIX     Installation prefix (default: /usr/local)"
            echo "  --help             Show this help message"
            exit 0
            ;;
        *)
            echo "Unknown option: $1"
            exit 1
            ;;
    esac
done

echo "=== Installing litehtml ==="
echo "Version: $VERSION"
echo "Platform: $PLATFORM"
echo "Install prefix: $INSTALL_DIR"
echo

# Determine download URL
if [[ "$VERSION" == "latest" ]]; then
    DOWNLOAD_URL="https://github.com/litehtml/litehtml/releases/latest/download/litehtml-$PLATFORM.tar.gz"
else
    DOWNLOAD_URL="https://github.com/litehtml/litehtml/releases/download/$VERSION/litehtml-$PLATFORM-$VERSION.tar.gz"
fi

# Create temporary directory
TEMP_DIR=$(mktemp -d)
trap "rm -rf $TEMP_DIR" EXIT

# Download and extract
echo "Downloading from: $DOWNLOAD_URL"
cd "$TEMP_DIR"
if command -v curl &> /dev/null; then
    curl -L -o litehtml.tar.gz "$DOWNLOAD_URL"
elif command -v wget &> /dev/null; then
    wget -O litehtml.tar.gz "$DOWNLOAD_URL"
else
    echo "Error: Neither curl nor wget found. Please install one of them."
    exit 1
fi

echo "Extracting..."
tar -xzf litehtml.tar.gz

# Install
echo "Installing to $INSTALL_DIR..."
if [[ "$EUID" -ne 0 && "$INSTALL_DIR" == "/usr/local" ]]; then
    echo "Note: Installation to $INSTALL_DIR requires root privileges"
    sudo cp -r * "$INSTALL_DIR/"
else
    cp -r * "$INSTALL_DIR/"
fi

echo "Installation completed successfully!"
echo
echo "To use litehtml in your project:"
echo "  - Include headers from: $INSTALL_DIR/include/litehtml/"
echo "  - Link against: $INSTALL_DIR/lib/liblitehtml.so (or .a)"
echo "  - Example: g++ -I$INSTALL_DIR/include -L$INSTALL_DIR/lib -llitehtml your_program.cpp"