// https://stackoverflow.com/a/39781697
// https://www.youtube.com/watch?v=qGxuD9o4GDA
// https://stackoverflow.com/a/14348924

#ifndef SCREENSHOT_H
#define SCREENSHOT_H

#include <opencv2/opencv.hpp>

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/extensions/XShm.h>
#include <sys/ipc.h>
#include <sys/shm.h>


#include <time.h>
#define FPS(start) (CLOCKS_PER_SEC / (clock()-start))

using namespace cv;

struct ScreenShot {

    Display* display;
    Window root;
    XWindowAttributes window_attributes;
    Screen* screen;
    XImage* ximg;
    XShmSegmentInfo shminfo;
    int x, y, width, height;
    bool init;

    ScreenShot(uint x, uint y, uint width, uint height);
    ~ScreenShot();

    void operator() (Mat& cv_img);
};

#endif