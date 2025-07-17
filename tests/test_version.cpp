#include <gtest/gtest.h>
#include <litehtml.h>
#include <litehtml/version.h>

TEST(VersionTest, VersionMacrosExist) {
    EXPECT_GE(LITEHTML_VERSION_MAJOR, 0);
    EXPECT_GE(LITEHTML_VERSION_MINOR, 0);
    EXPECT_GE(LITEHTML_VERSION_PATCH, 0);
    EXPECT_NE(LITEHTML_VERSION_STRING, "");
    EXPECT_NE(LITEHTML_VERSION_FULL, "");
}

TEST(VersionTest, VersionStringFormat) {
    std::string version_string = LITEHTML_VERSION_STRING;
    std::string version_full = LITEHTML_VERSION_FULL;
    
    // Version string should contain at least major.minor.patch
    EXPECT_TRUE(version_string.find('.') != std::string::npos);
    
    // Version full should contain the version string
    EXPECT_TRUE(version_full.find(version_string) != std::string::npos);
}