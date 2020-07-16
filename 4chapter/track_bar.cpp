//
//  track_bar.cpp
//  opencv_practice
//
//  Created by KimJunsik on 2019/11/20.
//  Copyright © 2019 KimJunsik. All rights reserved.
//

#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

string title = "trackbar event";
Mat image;

void onChange(int value, void *userdata)
{
    int add_value = value-130;
    cout << "추가 화솟값" << add_value << endl;
    
    Mat tmp = image + add_value;
    imshow(title, tmp);
}

int main()
{
    int value = 128;
    image = Mat(300,400,CV_8UC1, Scalar(120));
    
    namedWindow(title, WINDOW_AUTOSIZE);
    createTrackbar("bright value", title, &value, 255, onChange);
    
    imshow(title, image);
    waitKey(0);
    return 0;
}
