#include <iostream>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp> // Basic OpenCV strucs (e.g. `Mat`)
#include <opencv2/videoio/videoio.hpp> // Video write

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
    Mat image;
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cout << "Cannot detect camera.";
    }
    cap >> image;
    namedWindow("Captured", WINDOW_AUTOSIZE);
    imshow("Captured", image);

    // Luminance (Y or Lv,Ω) cd/m2
    Mat imageYUV;
    cvtColor(image, imageYUV, COLOR_RGB2YUV);
    Mat imageYUVSplit[3];
    split(imageYUV, imageYUVSplit);

    namedWindow("Captured Y", WINDOW_AUTOSIZE);
    imshow("Captured Y", imageYUVSplit[0]);

    cap.release();

    waitKey(0);
    return 0;
}
