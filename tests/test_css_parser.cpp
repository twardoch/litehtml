#include <gtest/gtest.h>
#include <litehtml.h>
#include <litehtml/css_parser.h>

using namespace litehtml;

TEST(CSSParserTest, ParseBasicColor) {
    css_parser parser;
    
    // Test basic color parsing
    web_color color = parser.parse_color("red");
    EXPECT_EQ(color.red, 255);
    EXPECT_EQ(color.green, 0);
    EXPECT_EQ(color.blue, 0);
    EXPECT_EQ(color.alpha, 255);
}

TEST(CSSParserTest, ParseHexColor) {
    css_parser parser;
    
    // Test hex color parsing
    web_color color = parser.parse_color("#FF0000");
    EXPECT_EQ(color.red, 255);
    EXPECT_EQ(color.green, 0);
    EXPECT_EQ(color.blue, 0);
    EXPECT_EQ(color.alpha, 255);
}

TEST(CSSParserTest, ParseRGBColor) {
    css_parser parser;
    
    // Test RGB color parsing
    web_color color = parser.parse_color("rgb(255, 0, 0)");
    EXPECT_EQ(color.red, 255);
    EXPECT_EQ(color.green, 0);
    EXPECT_EQ(color.blue, 0);
    EXPECT_EQ(color.alpha, 255);
}

TEST(CSSParserTest, ParseLength) {
    css_parser parser;
    
    // Test length parsing
    css_length length = parser.parse_length("10px");
    EXPECT_EQ(length.units(), css_units_px);
    EXPECT_EQ(length.value(), 10);
}

TEST(CSSParserTest, ParsePercentage) {
    css_parser parser;
    
    // Test percentage parsing
    css_length length = parser.parse_length("50%");
    EXPECT_EQ(length.units(), css_units_percentage);
    EXPECT_EQ(length.value(), 50);
}