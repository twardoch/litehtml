#include <gtest/gtest.h>
#include <litehtml.h>
#include <litehtml/utf8_strings.h>
#include <litehtml/web_color.h>

using namespace litehtml;

TEST(UtilsTest, UTF8StringHandling) {
    // Test UTF-8 string utilities
    std::string test_string = "Hello, 世界!";
    
    // Basic UTF-8 string should not crash
    EXPECT_NO_THROW(litehtml::utf8_to_wchar(test_string));
}

TEST(UtilsTest, WebColorConversion) {
    // Test web color utilities
    web_color red(255, 0, 0, 255);
    EXPECT_EQ(red.red, 255);
    EXPECT_EQ(red.green, 0);
    EXPECT_EQ(red.blue, 0);
    EXPECT_EQ(red.alpha, 255);
}

TEST(UtilsTest, WebColorFromString) {
    // Test color parsing from string
    web_color color = web_color::from_string("red");
    EXPECT_EQ(color.red, 255);
    EXPECT_EQ(color.green, 0);
    EXPECT_EQ(color.blue, 0);
    EXPECT_EQ(color.alpha, 255);
}

TEST(UtilsTest, WebColorHexParsing) {
    // Test hex color parsing
    web_color color = web_color::from_string("#FF0000");
    EXPECT_EQ(color.red, 255);
    EXPECT_EQ(color.green, 0);
    EXPECT_EQ(color.blue, 0);
    EXPECT_EQ(color.alpha, 255);
}