#!/bin/bash
# Install dependencies for litehtml
# this_file: scripts/install-deps.sh

set -e

echo "=== Installing litehtml dependencies ==="

# Detect OS
if [[ "$OSTYPE" == "linux-gnu"* ]]; then
    # Linux
    if command -v apt-get &> /dev/null; then
        # Ubuntu/Debian
        echo "Installing dependencies on Ubuntu/Debian..."
        sudo apt-get update
        sudo apt-get install -y \
            build-essential \
            cmake \
            git \
            libcairo2-dev \
            libpango1.0-dev \
            libgtk-3-dev \
            pkg-config
    elif command -v yum &> /dev/null; then
        # CentOS/RHEL
        echo "Installing dependencies on CentOS/RHEL..."
        sudo yum install -y \
            gcc-c++ \
            cmake \
            git \
            cairo-devel \
            pango-devel \
            gtk3-devel \
            pkg-config
    elif command -v pacman &> /dev/null; then
        # Arch Linux
        echo "Installing dependencies on Arch Linux..."
        sudo pacman -S --needed \
            base-devel \
            cmake \
            git \
            cairo \
            pango \
            gtk3 \
            pkg-config
    else
        echo "Unsupported Linux distribution"
        exit 1
    fi
elif [[ "$OSTYPE" == "darwin"* ]]; then
    # macOS
    echo "Installing dependencies on macOS..."
    if ! command -v brew &> /dev/null; then
        echo "Homebrew not found. Please install Homebrew first:"
        echo "https://brew.sh/"
        exit 1
    fi
    
    brew install \
        cmake \
        cairo \
        pango \
        gtk+3 \
        pkg-config
elif [[ "$OSTYPE" == "msys" || "$OSTYPE" == "win32" ]]; then
    # Windows
    echo "Installing dependencies on Windows..."
    echo "Please install the following manually:"
    echo "1. Visual Studio 2019 or later with C++ support"
    echo "2. CMake (https://cmake.org/download/)"
    echo "3. Git (https://git-scm.com/download/win)"
    echo "4. vcpkg for dependencies (https://vcpkg.io/)"
    echo "   - vcpkg install cairo pango gtk"
else
    echo "Unsupported operating system: $OSTYPE"
    exit 1
fi

echo "Dependencies installed successfully!"