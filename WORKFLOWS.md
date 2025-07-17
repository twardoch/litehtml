# GitHub Actions Workflows

This document contains the GitHub Actions workflows that should be added to the repository to enable CI/CD automation. These workflows require the `workflows` permission to be added to the repository.

## Files to create:

### 1. `.github/workflows/ci.yml` - Continuous Integration
This workflow runs on every push and pull request to test the code on multiple platforms.

### 2. `.github/workflows/release.yml` - Release Automation
This workflow triggers on git tags (`v*`) and creates multiplatform releases automatically.

### 3. `.github/workflows/docs.yml` - Documentation
This workflow generates and deploys API documentation to GitHub Pages.

### 4. Update `.github/workflows/cmake.yml` - Legacy Integration Tests
The existing cmake.yml workflow should be updated to focus on integration tests.

## Benefits of these workflows:

1. **Automated Testing**: Tests run on Ubuntu 22.04/24.04, Windows, and macOS (x86_64/ARM64)
2. **Code Quality**: Automated code formatting checks and static analysis
3. **Releases**: Automatic creation of multiplatform binary releases when tags are pushed
4. **Documentation**: API docs automatically generated and deployed
5. **Coverage**: Code coverage reporting for test quality metrics

## Setup Instructions:

1. Ensure the repository has the `workflows` permission
2. Add the workflow files from the implementation
3. Configure any necessary secrets (if needed)
4. Test by creating a git tag: `git tag v1.0.0 && git push origin v1.0.0`

## Manual Alternative:

Until the workflows are added, you can use the local scripts:

```bash
# Build and test locally
./scripts/build.sh
./scripts/test.sh

# Create releases manually
./scripts/release.sh
```

The release artifacts can then be manually uploaded to GitHub Releases.