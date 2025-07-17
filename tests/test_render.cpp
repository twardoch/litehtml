#include <gtest/gtest.h>
#include <litehtml.h>
#include "test_container.h"

using namespace litehtml;

class RenderTest : public ::testing::Test {
protected:
    void SetUp() override {
        container = std::make_unique<test_container>(800, 600, "");
    }
    
    std::unique_ptr<test_container> container;
};

TEST_F(RenderTest, RenderBasicLayout) {
    const char* html = R"(
        <html>
        <body>
            <div style="width: 100px; height: 50px; background: red;"></div>
        </body>
        </html>
    )";
    
    document::ptr doc = document::createFromString(html, container.get());
    ASSERT_NE(doc, nullptr);
    
    int width = doc->render(800);
    EXPECT_GT(width, 0);
    EXPECT_GT(doc->height(), 0);
}

TEST_F(RenderTest, RenderWithMargins) {
    const char* html = R"(
        <html>
        <body>
            <div style="margin: 10px; padding: 5px; width: 100px; height: 50px;"></div>
        </body>
        </html>
    )";
    
    document::ptr doc = document::createFromString(html, container.get());
    ASSERT_NE(doc, nullptr);
    
    int width = doc->render(800);
    EXPECT_GT(width, 0);
    EXPECT_GT(doc->height(), 0);
}

TEST_F(RenderTest, RenderTextContent) {
    const char* html = R"(
        <html>
        <body>
            <p>This is a paragraph with text content.</p>
        </body>
        </html>
    )";
    
    document::ptr doc = document::createFromString(html, container.get());
    ASSERT_NE(doc, nullptr);
    
    int width = doc->render(800);
    EXPECT_GT(width, 0);
    EXPECT_GT(doc->height(), 0);
}

TEST_F(RenderTest, RenderNestedElements) {
    const char* html = R"(
        <html>
        <body>
            <div>
                <p>Outer paragraph</p>
                <div>
                    <span>Inner span</span>
                </div>
            </div>
        </body>
        </html>
    )";
    
    document::ptr doc = document::createFromString(html, container.get());
    ASSERT_NE(doc, nullptr);
    
    int width = doc->render(800);
    EXPECT_GT(width, 0);
    EXPECT_GT(doc->height(), 0);
}