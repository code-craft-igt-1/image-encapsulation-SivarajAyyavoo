#include <iostream>
#include <memory>
#include <utility>
#include "./brightener.h"

int main() {
    // To be more user friendly, could also request input size of the image from the user
    unsigned int image_column_size = 512;
    unsigned int image_row_size = 512;

    auto image = std::make_shared<Image>(image_column_size, image_row_size);
    std::cout << "Brightening a " << image_column_size << " x " << image_row_size << " image\n";

    if (image->ValidateImage()) {
        // shared ptr allowed us to have multiple pointers safely share ownership of an object
        ImageBrightener brightener(image);

        int attenuatedCount = brightener.BrightenWholeImage();
        std::cout << "Attenuated " << attenuatedCount << " pixels\n";

        std::cout << "... in an image of: " << image->m_rows << " x " << image->m_columns << "\n";
        return 0;
    } else {
        std::cout << "Not a valid image... did nothing\n";
        return 1;
    }
}
