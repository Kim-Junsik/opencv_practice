//
//  window_move.cpp
//  opencv_practice
//
//  Created by KimJunsik on 2019/11/20.
//  Copyright © 2019 KimJunsik. All rights reserved.
//

#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
    Mat image1(300,400,CV_8U, Scalar(255));
    Mat image2(300,400,CV_8U, Scalar(100));
    string title1 = "white window";
    string title2 = "gray window";
    namedWindow(title1, WINDOW_AUTOSIZE);
    namedWindow(title2, WINDOW_NORMAL);
    moveWindow(title1, 100, 100);
    moveWindow(title2, 300, 200);
    imshow(title1, image1);
    imshow(title2, image2);
    
    waitKey();
    destroyAllWindows();
    return 0;
}
