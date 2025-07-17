#include <gtest/gtest.h>
#include <litehtml.h>
#include <litehtml/css_selector.h>

using namespace litehtml;

TEST(CSSSelectorTest, ParseSimpleSelector) {
    css_selector selector;
    
    // Test simple element selector
    EXPECT_TRUE(selector.parse("div"));
    EXPECT_EQ(selector.tag(), "div");
}

TEST(CSSSelectorTest, ParseClassSelector) {
    css_selector selector;
    
    // Test class selector
    EXPECT_TRUE(selector.parse(".my-class"));
    EXPECT_EQ(selector.class_name(), "my-class");
}

TEST(CSSSelectorTest, ParseIDSelector) {
    css_selector selector;
    
    // Test ID selector
    EXPECT_TRUE(selector.parse("#my-id"));
    EXPECT_EQ(selector.id(), "my-id");
}

TEST(CSSSelectorTest, ParseComplexSelector) {
    css_selector selector;
    
    // Test complex selector
    EXPECT_TRUE(selector.parse("div.my-class#my-id"));
    EXPECT_EQ(selector.tag(), "div");
    EXPECT_EQ(selector.class_name(), "my-class");
    EXPECT_EQ(selector.id(), "my-id");
}

TEST(CSSSelectorTest, ParseAttributeSelector) {
    css_selector selector;
    
    // Test attribute selector
    EXPECT_TRUE(selector.parse("[href]"));
    // Basic attribute selector should work
}