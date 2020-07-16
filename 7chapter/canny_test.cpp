//
//  canny_test.cpp
//  opencv_practice
//
//  Created by KimJunsik on 2019/12/20.
//  Copyright © 2019 KimJunsik. All rights reserved.
//

#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int th = 50;
Mat image, gray, edge;

void onTrackbar(int, void*)
{
    GaussianBlur(gray, edge, Size(3, 3), 0.7);
    Canny(edge, edge, th, th * 2, 3);

    Mat color_edge;
    image.copyTo(color_edge, edge);
    imshow("color edge", color_edge);
}

int main()
{
    image = imread("./7chapter/image/smoothing.jpg", 1);
    CV_Assert(image.data);
    cvtColor(image, gray, COLOR_BGR2GRAY);

    namedWindow("color edge", 1);
    createTrackbar("Canny th", "color edge", &th, 100, onTrackbar);
    onTrackbar(th, 0);

    waitKey(0);
    return 0;
}
