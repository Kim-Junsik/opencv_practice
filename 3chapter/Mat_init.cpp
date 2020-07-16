//
//  Mat_init.cpp
//  opencv_practice
//
//  Created by KimJunsik on 2019/11/14.
//  Copyright © 2019 KimJunsik. All rights reserved.
//

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat m1 = Mat::ones(3, 5, CV_8UC1);
    Mat m2 = Mat::zeros(3,5,CV_8UC1);
    Mat m3 = Mat::eye(3,3,CV_8UC1);
    
    cout << "[m1] = " << endl << m1 << endl;
    cout << "[m2] = " << endl << m2 << endl;
    cout << "[m3] = " << endl << m3 << endl;
    return 0;
}
