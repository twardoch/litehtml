# Changelog

All notable changes to litehtml will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Added
- Git-tag-based semantic versioning system
- Comprehensive unit test suite using GoogleTest
- Local build, test, and release scripts
- GitHub Actions CI/CD pipeline with multiplatform support
- Automated release creation with binary artifacts
- Documentation generation with Doxygen
- Code quality checks with clang-format and cppcheck
- Code coverage reporting
- Installation script for easy deployment
- Version header file with compile-time version information

### Changed
- Updated CMake build system to support modern practices
- Improved GitHub Actions workflows for better reliability
- Enhanced README with detailed build and usage instructions

### Fixed
- Build system now properly handles git-based versioning
- Improved test reliability and cross-platform compatibility

## [0.1.0] - TBD

### Added
- Initial release with git-tag-based versioning
- Complete CI/CD pipeline
- Multiplatform binary releases
- Comprehensive testing framework

---

## Release Process

1. Update version in git tag: `git tag v1.0.0`
2. Push tag: `git push origin v1.0.0`
3. GitHub Actions will automatically:
   - Build and test on multiple platforms
   - Create release artifacts
   - Generate release notes
   - Upload binaries to GitHub Releases

## Version Numbering

This project uses [Semantic Versioning](https://semver.org/):
- **MAJOR**: Incompatible API changes
- **MINOR**: New functionality in a backwards compatible manner
- **PATCH**: Backwards compatible bug fixes

## Development Builds

Development builds are automatically versioned as:
- `X.Y.Z-N` where N is the number of commits since the last tag
- `X.Y.Z-N-dirty` if there are uncommitted changes