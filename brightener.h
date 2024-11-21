#pragma once
#include <memory>
#include "./image.h"

const unsigned int MAX_BRIGHTNESS_VAL = 255;
const unsigned int GRAYSCALE_VAL_TO_BRIGHTEN = 25;

class ImageBrightener {
 private:
    std::shared_ptr<Image> m_inputImage;
 public:
    explicit ImageBrightener(std::shared_ptr<Image> inputImage);
    int BrightenWholeImage();
};
