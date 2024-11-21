#pragma once
#include <cstdint>
#include <iostream>
#include <memory>

const unsigned int MAX_IMAGE_COLUMN_SIZE = 1024;
const unsigned int MAX_IMAGE_ROW_SIZE = 1024;

class Image {
 public:
    Image(uint16_t rows, uint16_t columns): m_rows(rows), m_columns(columns) {
        pixels = std::make_unique<uint8_t[]>(rows * columns);
    }
    ~Image() {
        std::cout << "Image destroyed. Pixel memory automatically freed.\n";
    }
    uint8_t GetPixel(uint16_t x, uint16_t y) const {
        return pixels[x * m_columns + y];
    }
    void SetPixel(uint16_t x, uint16_t y, uint8_t value) {
        pixels[x * m_columns + y] = value;
    }
    bool ValidateImage() {
        if (m_columns <= MAX_IMAGE_COLUMN_SIZE && m_rows <= MAX_IMAGE_ROW_SIZE) {
            return true;
        } else {
            return false;
        }
    }
    const uint16_t m_rows;
    const uint16_t m_columns;
    std::unique_ptr<uint8_t[]> pixels;  // max 1k x 1k image
};
