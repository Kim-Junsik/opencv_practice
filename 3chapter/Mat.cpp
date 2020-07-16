//
//  Mat.cpp
//  opencv_practice
//
//  Created by KimJunsik on 2019/11/07.
//  Copyright © 2019 KimJunsik. All rights reserved.
//

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    float data[] {1.2f, 2.3f, 3.2f, 4.5f, 5.f, 6.5f};
    
    Mat m1(2,3,CV_8U,Scalar(0));
    Mat m2(2,3,CV_8U, Scalar(300));
    Mat m3(2,3,CV_16S, Scalar(300));
    Mat m4(2,3,CV_32F, data);
    
    Size sz(2,3);
    Mat m5(Size(2,3), CV_64F);
    Mat m6(sz, CV_32F, data);
    
    cout << "[M1] = " << endl << m1 << endl;
    cout << "[M2] = " << endl << m2 << endl;
    cout << "[M3] = " << endl << m3 << endl;
    cout << "[M4] = " << endl << m4 << endl << endl;
    cout << "[M5] = " << endl << m5 << endl;
    cout << "[M6] = " << endl << m6 << endl;
    return 0;
}
