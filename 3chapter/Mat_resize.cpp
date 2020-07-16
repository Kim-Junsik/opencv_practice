//
//  Mat_resize.cpp
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
    Mat m = (Mat_<uchar>(2,4) << 1,2,3,4,5,6,7,8);
    cout << "[m] = " << endl << m << endl << endl;
    
    m.resize(1);
    cout << "m.resize(1) = " << endl << m << endl << endl;
    m.resize(3);
    cout << "m.resize(3) = " << endl << m << endl << endl;
    m.resize(5, Scalar(50));
    cout << "m.resize(5, Scalar(50)) = " << endl << m << endl << endl;
    
    return 0;
}
