# Building litehtml

This document describes how to build litehtml from source.

## Prerequisites

### Linux (Ubuntu/Debian)
```bash
sudo apt-get update
sudo apt-get install -y build-essential cmake git libcairo2-dev libpango1.0-dev libgtk-3-dev pkg-config
```

### Linux (CentOS/RHEL)
```bash
sudo yum install -y gcc-c++ cmake git cairo-devel pango-devel gtk3-devel pkg-config
```

### macOS
```bash
brew install cmake cairo pango gtk+3 pkg-config
```

### Windows
1. Install Visual Studio 2019 or later with C++ support
2. Install CMake from https://cmake.org/download/
3. Install Git from https://git-scm.com/download/win
4. Install vcpkg for dependencies:
   ```cmd
   git clone https://github.com/Microsoft/vcpkg.git
   cd vcpkg
   .\bootstrap-vcpkg.bat
   .\vcpkg integrate install
   .\vcpkg install cairo pango gtk --triplet x64-windows
   ```

## Quick Start

### Using the build script (recommended)
```bash
# Install dependencies (Linux/macOS)
./scripts/install-deps.sh

# Build
./scripts/build.sh

# Run tests
./scripts/test.sh
```

### Manual build
```bash
# Clone the repository
git clone https://github.com/litehtml/litehtml.git
cd litehtml

# Create build directory
mkdir build && cd build

# Configure
cmake .. -DCMAKE_BUILD_TYPE=Release -DLITEHTML_BUILD_TESTING=ON

# Build
cmake --build . --config Release --parallel

# Test
ctest -C Release --parallel
```

## Build Options

| Option | Default | Description |
|--------|---------|-------------|
| `LITEHTML_BUILD_TESTING` | OFF | Build unit tests |
| `EXTERNAL_GUMBO` | OFF | Use external gumbo parser instead of bundled |
| `CMAKE_BUILD_TYPE` | Release | Build type (Debug, Release, RelWithDebInfo, MinSizeRel) |
| `CMAKE_INSTALL_PREFIX` | /usr/local | Installation prefix |

## Examples

### Build with tests
```bash
cmake .. -DLITEHTML_BUILD_TESTING=ON
cmake --build . --parallel
ctest --parallel
```

### Build for development
```bash
cmake .. -DCMAKE_BUILD_TYPE=Debug -DLITEHTML_BUILD_TESTING=ON
cmake --build . --parallel
```

### Cross-compilation
```bash
# For ARM64 on Linux
cmake .. -DCMAKE_TOOLCHAIN_FILE=path/to/arm64-toolchain.cmake
cmake --build . --parallel
```

## Installation

### From source
```bash
cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local
cmake --build . --parallel
sudo cmake --install .
```

### Using install script
```bash
curl -sSL https://raw.githubusercontent.com/litehtml/litehtml/master/install.sh | bash
```

## Troubleshooting

### Missing dependencies
Make sure all required dependencies are installed:
```bash
# Linux
./scripts/install-deps.sh

# macOS
brew install cmake cairo pango gtk+3

# Windows
vcpkg install cairo pango gtk --triplet x64-windows
```

### Build fails with "Git not found"
Make sure git is installed and in your PATH:
```bash
git --version
```

### Tests fail
Some tests may require additional setup or may be environment-specific. Check the test output for specific error messages.

### Windows-specific issues
- Use Visual Studio Developer Command Prompt
- Make sure vcpkg is properly integrated
- Use forward slashes in paths or escape backslashes

## Advanced Usage

### Static library
```bash
cmake .. -DBUILD_SHARED_LIBS=OFF
```

### Custom installation directory
```bash
cmake .. -DCMAKE_INSTALL_PREFIX=/opt/litehtml
```

### Debug build with sanitizers
```bash
cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_FLAGS="-fsanitize=address -fsanitize=undefined"
```