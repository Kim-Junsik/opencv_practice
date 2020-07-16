//
//  image_channels.cpp
//  opencv_practice
//
//  Created by KimJunsik on 2019/12/03.
//  Copyright © 2019 KimJunsik. All rights reserved.
//

#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main()
{
    Mat image = imread("./5chapter/image/color.jpg", IMREAD_COLOR);
    CV_Assert(image.data);
    
    Mat bgr[3];
    split(image, bgr);
    
    imshow("image", image);
    imshow("Blue",bgr[0]);
    imshow("Green",bgr[1]);
    imshow("Red", bgr[2]);
    waitKey(0);
    return 0;
}
