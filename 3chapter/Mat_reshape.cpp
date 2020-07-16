//
//  Mat_reshape.cpp
//  opencv_practice
//
//  Created by KimJunsik on 2019/11/14.
//  Copyright © 2019 KimJunsik. All rights reserved.
//

#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace cv;

void print_matInfo(string m_name, Mat m)
{
    cout << "[" << m_name << " matrix]" << endl;
    cout << "channels = " << m.channels() << endl;
    cout << "rows * cols = " << m.rows << " X " << m.cols << endl << endl;
}

int main()
{
    Mat m1(2,6,CV_8U);
    Mat m2 = m1.reshape(2);
    Mat m3 = m1.reshape(3,2);
    
    print_matInfo("m1(2,6)", m1);
    print_matInfo("m2 = m1_reshape(2)", m2);
    print_matInfo("m3 = m1.reshape(3,2)", m3);
    
    m1.create(3, 5, CV_16S);
    print_matInfo("m1.create(3,5)", m1);
    
    Mat m4;
    Mat add1(2,3,CV_8UC1,Scalar(100));
    Mat add2 = (Mat)Mat::eye(4,3,CV_8UC1);
    m4.push_back(add1);
    m4.push_back(add2);
    
    cout << "[m4] = " << endl << m4 << endl << endl;
    
    m4.pop_back(3);
    cout << "[m4] = " << endl << m4 << endl << endl;
    return 0;
}
