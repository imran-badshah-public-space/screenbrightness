#include "Luminance.h"

Mat Luminance(Mat &image) {
    // Luminance (Y or Lv,Ω) cd/m2
    Mat imageYUV;
    cvtColor(image, imageYUV, COLOR_RGB2YUV);
    Mat imageYUVSplit[3];
    split(imageYUV, imageYUVSplit);

    return imageYUVSplit[0];
}

float channelMean(Mat &channel) {
    return  mean(channel)[0];
}