#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp> // Basic OpenCV strucs (e.g. `Mat`)
#include <opencv2/videoio/videoio.hpp> // Video write

using namespace cv;

Mat Luminance(Mat image) {
    // Luminance (Y or Lv,Ω) cd/m2
    Mat imageYUV;
    cvtColor(image, imageYUV, COLOR_RGB2YUV);
    Mat imageYUVSplit[3];
    split(imageYUV, imageYUVSplit);

    return imageYUVSplit[0];
}