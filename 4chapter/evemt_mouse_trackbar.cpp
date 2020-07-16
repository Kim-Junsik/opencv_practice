//
//  evemt_mouse_trackbar.cpp
//  opencv_practice
//
//  Created by KimJunsik on 2019/11/20.
//  Copyright © 2019 KimJunsik. All rights reserved.
//

#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

string title = "bright change", bar_name = "bright value";
Mat image;

void onChange(int value, void *userdata)
{
    int add_value = value-130;
    cout << "추가 화솟값" << add_value << endl;
    
    Mat tmp = image + add_value;
    imshow(title, tmp);
}

void onMouse(int event, int x, int y, int flags, void *param)
{
    if(event == EVENT_LBUTTONDOWN)
    {
        add(image, 10, image);
        setTrackbarPos(bar_name, title, image.at<uchar>(0,0));
        cout << image.at<uchar>(0) <<endl;
        imshow(title, image);
    }
    else if(event == EVENT_RBUTTONDOWN)
    {
        subtract(image, 10, image);
        setTrackbarPos(bar_name, title, image.at<uchar>(0,0));
        imshow(title, image);
    }
}

int main()
{
    int value = 130;
    image = Mat(300,500,CV_8UC1, Scalar(120));
    namedWindow(title, WINDOW_AUTOSIZE);
    createTrackbar(bar_name, title, &value, 255, onChange);
    setMouseCallback(title, onMouse, 0);
    
    imshow(title, image);
    waitKey(0);
    return 0;
}
