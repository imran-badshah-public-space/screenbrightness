#include <iostream>
#include <stdlib.h>

#include <opencv2/highgui/highgui.hpp>
// #include <opencv2/imgproc/imgproc.hpp>
// #include <opencv2/core/core.hpp> // Basic OpenCV strucs (e.g. `Mat`)
// #include <opencv2/videoio/videoio.hpp> // Video write

#include "Luminance.h"
#include "ScreenShot.h"

using namespace std;

int main(int argc, char** argv) {

    const Size finalResolution(256, 256);

    Mat image;
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cout << "Cannot detect camera.";
    }
    cap >> image;
    resize(image, image, finalResolution); //resize image
    namedWindow("Captured", WINDOW_AUTOSIZE);
    imshow("Captured", image);

    Mat* imagePtr = &image;
    // Luminance
    Mat luminanceImage = Luminance(*imagePtr);
    namedWindow("Captured Y", WINDOW_AUTOSIZE);
    imshow("Captured Y", luminanceImage);



    cout << channelMean(luminanceImage) << endl;

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
    resize(screenshot, screenshot, finalResolution); //resize image
    namedWindow("Captured Y", WINDOW_AUTOSIZE);
    imshow("screenshot", screenshot);

    // Luminance
    Mat screenshotLuminanceImage = Luminance(screenshot);
    namedWindow("screenshot Luminance Y", WINDOW_AUTOSIZE);
    imshow("screenshot Luminance Y", screenshotLuminanceImage);

    cout << channelMean(screenshotLuminanceImage) << endl;


    waitKey(0);

    // On exit: Reset to max brightness
    system("src/adjustScreenBrightness.sh max");
    return 0;
}
