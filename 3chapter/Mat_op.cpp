//
//  Mat_op.cpp
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
    Mat m1(2,3,CV_8U,2);
    Mat m2(2,3,CV_8U,Scalar(10));
    
    Mat m3 = m1 + m2;
    Mat m4 = m2 - 6;
    Mat m5 = m1;
    
    cout << "[m2] = " << endl << m2 << endl;
    cout << "[m3] = " << endl << m3 << endl;
    cout << "[m4] = " << endl << m3 << endl;
    
    cout << "[m1] = " << endl << m1 << endl;
    cout << "[m5] = " << endl << m5 << endl;
    m5 = 100;
    cout << "[m1] = " << endl << m1 << endl;
    cout << "[m5] = " << endl << m5 << endl;
    return 0;
}
