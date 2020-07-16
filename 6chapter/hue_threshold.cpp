//
//  hue_threshold.cpp
//  opencv_practice
//
//  Created by KimJunsik on 2019/12/13.
//  Copyright © 2019 KimJunsik. All rights reserved.
//

#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
Range th(50, 100);
Mat hue;

void onThreshold(int  value, void*  userdata)
{
    Mat result = Mat(hue.size(), CV_8U, Scalar(0));

    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; j++)
        {
            bool ck = hue.at<uchar>(i, j) >= th.start && hue.at<uchar>(i, j) < th.end;
            result.at<uchar>(i, j) = (ck) ? 255 : 0;
        }
    }
//    cout << "( th.start : " << th.start << "  th.end : " << th.end << "  )" << endl;
    
//    // getpos and print pos
//    int start_value = getTrackbarPos("Hue_th1", "result");
//    cout << start_value << endl;
    
    imshow("result", result);
}

int main()
{
    Mat BGR_img = imread("./6chapter/image/color_space.jpg", 1);
    CV_Assert(BGR_img.data);

    Mat HSV, hsv[3];
    cvtColor(BGR_img, HSV, COLOR_BGR2HSV);
    split(HSV, hsv);
    hsv[0].copyTo(hue);

    namedWindow("result", WINDOW_AUTOSIZE);
    createTrackbar("Hue_th1", "result", &th.start, 255, onThreshold);
    createTrackbar("Hue_th2", "result", &th.end, 255, onThreshold);

    imshow("BGR_img", BGR_img);
    onThreshold(0,0);
//    int pos;
//    cin>>pos;
//    setTrackbarPos("Hue_th1", "result", pos);
    

    waitKey(0);
    return 0;
}
