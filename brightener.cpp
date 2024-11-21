#include "./brightener.h"
#include <utility>

ImageBrightener::ImageBrightener(std::shared_ptr<Image> inputImage)
    : m_inputImage(inputImage) {
}

int ImageBrightener::BrightenWholeImage() {
    // For brightening, we add a certain grayscale to every pixel.
    // While brightening, some pixels may cross the max brightness. They are
    // called 'attenuated' pixels
    int attenuatedPixelCount = 0;
    for (int imageArrayIndex = 0;
        imageArrayIndex < (m_inputImage->m_columns * m_inputImage->m_rows);
        imageArrayIndex++) {
        if (m_inputImage->pixels[imageArrayIndex] >
            (MAX_BRIGHTNESS_VAL - GRAYSCALE_VAL_TO_BRIGHTEN)) {
            ++attenuatedPixelCount;
            m_inputImage->pixels[imageArrayIndex] = MAX_BRIGHTNESS_VAL;
        } else {
            m_inputImage->pixels[imageArrayIndex] += GRAYSCALE_VAL_TO_BRIGHTEN;
        }
    }

    return attenuatedPixelCount;
}
