/**
 * Basic usage example for litehtml
 * this_file: examples/basic_usage.cpp
 * 
 * This example demonstrates how to:
 * 1. Create a simple document container
 * 2. Parse HTML content
 * 3. Render and draw the document
 */

#include <litehtml.h>
#include <iostream>
#include <fstream>

// Simple document container implementation
class simple_container : public litehtml::document_container {
public:
    // Font management
    litehtml::uint_ptr create_font(const char* faceName, int size, int weight, 
                                  litehtml::font_style italic, unsigned int decoration, 
                                  litehtml::font_metrics* fm) override {
        // Simple font creation - in real implementation you'd use actual font libraries
        if (fm) {
            fm->height = size;
            fm->ascent = size * 0.8;
            fm->descent = size * 0.2;
            fm->x_height = size * 0.5;
        }
        return (litehtml::uint_ptr)1; // dummy font handle
    }
    
    void delete_font(litehtml::uint_ptr hFont) override {
        // Clean up font resources
    }
    
    int text_width(const char* text, litehtml::uint_ptr hFont) override {
        // Simple text width calculation - in real implementation use actual text measurement
        return strlen(text) * 8; // assume 8px per character
    }
    
    void draw_text(litehtml::uint_ptr hdc, const char* text, litehtml::uint_ptr hFont, 
                   litehtml::web_color color, const litehtml::position& pos) override {
        std::cout << "Drawing text: '" << text << "' at (" << pos.x << ", " << pos.y << ")" << std::endl;
    }
    
    // Measurements
    int pt_to_px(int pt) const override {
        return pt * 96 / 72; // standard DPI conversion
    }
    
    int get_default_font_size() const override {
        return 16; // 16px default font size
    }
    
    const char* get_default_font_name() const override {
        return "Arial, sans-serif";
    }
    
    // Image handling
    void load_image(const char* src, const char* baseurl, bool redraw_on_ready) override {
        std::cout << "Loading image: " << src << std::endl;
    }
    
    void get_image_size(const char* src, const char* baseurl, litehtml::size& sz) override {
        // Default image size
        sz.width = 100;
        sz.height = 100;
    }
    
    void draw_image(litehtml::uint_ptr hdc, const litehtml::background_layer& layer, 
                   const litehtml::string& url, const litehtml::string& base_url) override {
        std::cout << "Drawing image: " << url << std::endl;
    }
    
    // Drawing operations
    void draw_solid_fill(litehtml::uint_ptr hdc, const litehtml::background_layer& layer, 
                        const litehtml::web_color& color) override {
        std::cout << "Drawing solid fill: rgb(" << (int)color.red << "," << (int)color.green << "," << (int)color.blue << ")" << std::endl;
    }
    
    void draw_linear_gradient(litehtml::uint_ptr hdc, const litehtml::background_layer& layer, 
                             const litehtml::background_layer::linear_gradient& gradient) override {
        std::cout << "Drawing linear gradient" << std::endl;
    }
    
    void draw_radial_gradient(litehtml::uint_ptr hdc, const litehtml::background_layer& layer, 
                             const litehtml::background_layer::radial_gradient& gradient) override {
        std::cout << "Drawing radial gradient" << std::endl;
    }
    
    void draw_conic_gradient(litehtml::uint_ptr hdc, const litehtml::background_layer& layer, 
                            const litehtml::background_layer::conic_gradient& gradient) override {
        std::cout << "Drawing conic gradient" << std::endl;
    }
    
    void draw_borders(litehtml::uint_ptr hdc, const litehtml::borders& borders, 
                     const litehtml::position& draw_pos, bool root) override {
        std::cout << "Drawing borders" << std::endl;
    }
    
    void draw_list_marker(litehtml::uint_ptr hdc, const litehtml::list_marker& marker) override {
        std::cout << "Drawing list marker" << std::endl;
    }
    
    // Element creation
    litehtml::element::ptr create_element(const char* tag_name, 
                                         const litehtml::string_map& attributes, 
                                         const litehtml::document::ptr& doc) override {
        return nullptr; // Use default element creation
    }
    
    // Media queries
    void get_media_features(litehtml::media_features& media) const override {
        media.type = litehtml::media_type_screen;
        media.width = 1024;
        media.height = 768;
        media.device_width = 1024;
        media.device_height = 768;
        media.color = 8;
        media.color_index = 256;
        media.monochrome = 0;
        media.resolution = 96;
    }
    
    void get_language(litehtml::string& language, litehtml::string& culture) const override {
        language = "en";
        culture = "US";
    }
    
    // Callbacks
    void link(const litehtml::document::ptr& doc, const litehtml::element::ptr& el) override {
        // Handle link elements
    }
    
    void transform_text(litehtml::string& text, litehtml::text_transform tt) override {
        // Transform text according to CSS text-transform property
    }
    
    void set_clip(const litehtml::position& pos, const litehtml::border_radiuses& bdr_radius) override {
        // Set clipping region
    }
    
    void del_clip() override {
        // Remove clipping region
    }
    
    void set_caption(const char* caption) override {
        // Set window caption
    }
    
    void set_base_url(const char* base_url) override {
        // Set base URL for relative links
    }
    
    void on_anchor_click(const char* url, const litehtml::element::ptr& el) override {
        std::cout << "Anchor clicked: " << url << std::endl;
    }
    
    void on_mouse_event(const litehtml::element::ptr& el, litehtml::mouse_event event) override {
        // Handle mouse events
    }
    
    void set_cursor(const char* cursor) override {
        std::cout << "Setting cursor: " << cursor << std::endl;
    }
    
    void import_css(litehtml::string& text, const litehtml::string& url, litehtml::string& baseurl) override {
        // Import external CSS
    }
    
    void get_client_rect(litehtml::position& client) const override {
        client.x = 0;
        client.y = 0;
        client.width = 1024;
        client.height = 768;
    }
};

int main() {
    std::cout << "=== litehtml Basic Usage Example ===" << std::endl;
    std::cout << "Version: " << LITEHTML_VERSION_STRING << std::endl;
    std::cout << std::endl;
    
    // Create a document container
    simple_container container;
    
    // Sample HTML content
    const char* html_content = R"(
        <!DOCTYPE html>
        <html>
        <head>
            <title>litehtml Example</title>
            <style>
                body {
                    font-family: Arial, sans-serif;
                    margin: 20px;
                    background-color: #f0f0f0;
                }
                h1 {
                    color: #333;
                    font-size: 24px;
                }
                p {
                    color: #666;
                    line-height: 1.6;
                }
                .highlight {
                    background-color: yellow;
                    padding: 2px 4px;
                }
            </style>
        </head>
        <body>
            <h1>Hello, litehtml!</h1>
            <p>This is a <span class="highlight">basic example</span> of using litehtml.</p>
            <p>litehtml is a lightweight HTML/CSS rendering engine.</p>
        </body>
        </html>
    )";
    
    try {
        // Create document from HTML string
        std::cout << "Creating document from HTML..." << std::endl;
        litehtml::document::ptr doc = litehtml::document::createFromString(
            html_content, 
            &container,
            litehtml::master_css  // default stylesheet
        );
        
        if (!doc) {
            std::cerr << "Failed to create document!" << std::endl;
            return 1;
        }
        
        std::cout << "Document created successfully!" << std::endl;
        
        // Render the document
        std::cout << "Rendering document..." << std::endl;
        int max_width = 800;
        int best_width = doc->render(max_width);
        
        std::cout << "Document rendered!" << std::endl;
        std::cout << "Optimal width: " << best_width << "px" << std::endl;
        std::cout << "Document size: " << doc->width() << "x" << doc->height() << "px" << std::endl;
        
        // Draw the document
        std::cout << "Drawing document..." << std::endl;
        litehtml::uint_ptr hdc = 0; // dummy drawing context
        litehtml::position clip(0, 0, doc->width(), doc->height());
        doc->draw(hdc, 0, 0, &clip);
        
        std::cout << "Document drawn successfully!" << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}