#include "Luminance.h"


Mat Luminance(Mat *image) {
    // Luminance (Y or Lv,Ω) cd/m2
    cvtColor(*image, *image, COLOR_RGB2YUV);
    Mat imageYUVSplit[3];
    split(*image, imageYUVSplit);
    return imageYUVSplit[0];
}

float channelMean(Mat *channel) {
    return  mean(*channel)[0];
}

auto downscale = [] (Mat *image, const Size* finalResolution) -> Mat* {
    resize(*image, *image, *finalResolution); //resize image
    return image;
};

float meanLuminance(Mat *image, const Size* finalResolution) {
    Mat *downscaledImage = downscale(image, finalResolution);
    Mat channel = Luminance(downscaledImage);
    return channelMean(&channel);
}