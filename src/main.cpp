#include <iostream>

#include <opencv2/highgui/highgui.hpp>
// #include <opencv2/imgproc/imgproc.hpp>
// #include <opencv2/core/core.hpp> // Basic OpenCV strucs (e.g. `Mat`)
// #include <opencv2/videoio/videoio.hpp> // Video write

#include "Luminance.h"

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

    // Luminance
    Mat luminanceImage = Luminance(image);
    namedWindow("Captured Y", WINDOW_AUTOSIZE);
    imshow("Captured Y", luminanceImage);

    cap.release();

    waitKey(0);
    return 0;
}
