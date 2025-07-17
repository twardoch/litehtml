#include <gtest/gtest.h>
#include <litehtml.h>
#include "test_container.h"

using namespace litehtml;

class DocumentTest : public ::testing::Test {
protected:
    void SetUp() override {
        container = std::make_unique<test_container>(800, 600, "");
    }
    
    std::unique_ptr<test_container> container;
};

TEST_F(DocumentTest, CreateFromSimpleHTML) {
    const char* html = "<html><body><h1>Hello World</h1></body></html>";
    
    document::ptr doc = document::createFromString(html, container.get());
    ASSERT_NE(doc, nullptr);
    
    // Basic document should be created successfully
    EXPECT_GT(doc->content_width(), 0);
    EXPECT_GT(doc->content_height(), 0);
}

TEST_F(DocumentTest, CreateFromEmptyHTML) {
    const char* html = "";
    
    document::ptr doc = document::createFromString(html, container.get());
    ASSERT_NE(doc, nullptr);
    
    // Even empty HTML should create a valid document
}

TEST_F(DocumentTest, CreateFromHTMLWithCSS) {
    const char* html = R"(
        <html>
        <head>
            <style>
                body { margin: 0; padding: 10px; }
                h1 { color: red; font-size: 24px; }
            </style>
        </head>
        <body>
            <h1>Styled Header</h1>
        </body>
        </html>
    )";
    
    document::ptr doc = document::createFromString(html, container.get());
    ASSERT_NE(doc, nullptr);
    
    // Document with CSS should be created successfully
    EXPECT_GT(doc->content_width(), 0);
    EXPECT_GT(doc->content_height(), 0);
}

TEST_F(DocumentTest, RenderDocument) {
    const char* html = "<html><body><p>Test paragraph</p></body></html>";
    
    document::ptr doc = document::createFromString(html, container.get());
    ASSERT_NE(doc, nullptr);
    
    // Render the document
    int width = doc->render(800);
    EXPECT_GT(width, 0);
    EXPECT_LE(width, 800);
    
    // After rendering, document should have dimensions
    EXPECT_GT(doc->height(), 0);
    EXPECT_GT(doc->width(), 0);
}

TEST_F(DocumentTest, DrawDocument) {
    const char* html = "<html><body><p>Test paragraph</p></body></html>";
    
    document::ptr doc = document::createFromString(html, container.get());
    ASSERT_NE(doc, nullptr);
    
    // Render first
    doc->render(800);
    
    // Draw should not crash
    uint_ptr hdc = 0; // Mock drawing context
    position clip(0, 0, doc->width(), doc->height());
    EXPECT_NO_THROW(doc->draw(hdc, 0, 0, &clip));
}