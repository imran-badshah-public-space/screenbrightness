#include <iostream>
#include <stdlib.h>

#include <opencv2/highgui/highgui.hpp>
// #include <opencv2/imgproc/imgproc.hpp>
// #include <opencv2/core/core.hpp> // Basic OpenCV strucs (e.g. `Mat`)
// #include <opencv2/videoio/videoio.hpp> // Video write

#include "Luminance.h"
#include "ScreenShot.h"

using namespace std;
extern const Size downscaleResolution(256, 256);

int main(int argc, char** argv) {

    Mat image;
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cout << "Cannot detect camera.";
    }
    cap >> image;
    namedWindow("Captured", WINDOW_AUTOSIZE);
    imshow("Captured", image);

    cout << meanLuminance(&image, &downscaleResolution) << endl;
    // Luminance
    namedWindow("Captured Y", WINDOW_AUTOSIZE);
    imshow("Captured Y", image);

    // Hard-coded to try out bash script
    // TO-DO: Find out max luminance and set ratio for now
    // TO-DO: Let user be prompted to input (set) brightness
    system("src/adjustScreenBrightness.sh 0.8");
    cap.release();

    // Take screenshot
    ScreenShot screen(0, 0, 1920, 1080);
    Mat screenshot;
    screen(screenshot);
    // Resize to standard down-scaled resolution
    namedWindow("screenshot", WINDOW_AUTOSIZE);
    imshow("screenshot", screenshot);

    // Luminance
    cout << meanLuminance(&screenshot, &downscaleResolution) << endl;
    namedWindow("screenshot Luminance Y", WINDOW_AUTOSIZE);
    imshow("screenshot Luminance Y", screenshot);

    waitKey(0);

    // On exit: Reset to max brightness
    system("src/adjustScreenBrightness.sh max");
    return 0;
}
