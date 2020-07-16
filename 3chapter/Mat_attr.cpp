//
//  Mat_attr.cpp
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
    Mat m1(4,3,CV_32FC3);
    cout << m1.dims <<endl;
    cout << m1.rows << endl;
    cout << m1.cols << endl;
    cout << m1.size() << endl << endl;
    cout << m1.total() << endl;
    cout << m1.elemSize() << endl;
    cout << m1.elemSize1() << endl << endl;
    cout << m1.type() << endl;
    cout << ((m1.channels() - 1) << 3) + m1.depth() << endl;
    cout << m1.depth() << endl;
    cout << m1.channels() << endl;
    cout << m1.step << endl;
    cout << m1.step1() << endl;
    return 0;
}
