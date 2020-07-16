//
//  mat_array.cpp
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
    Mat image = imread("./5chapter/image/flip_test.jpg",IMREAD_COLOR);
    CV_Assert(image.data);
    
    Mat x_axis, y_axis, xy_axis, rep_img, trans_img;
    flip(image, x_axis, 0);
    flip(image, y_axis, 1);
    flip(image, xy_axis, -1);
    
    repeat(image, 1, 2, rep_img);
    transpose(image, trans_img);
    
    imshow("image", image);
    imshow("x_axis", x_axis);
    imshow("y_axis", y_axis);
    imshow("xy_asix", xy_axis);
    imshow("rep_image",rep_img);
    imshow("trans_img",trans_img);
    waitKey(0);
    return 0;
}
