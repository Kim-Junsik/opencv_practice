//
//  main.cpp
//  opencv_practice
//
//  Created by KimJunsik on 2019/11/06.
//  Copyright © 2019 KimJunsik. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
//#include <opencv4/opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int args, const char * argv[])
{
    cout<<"OpenCV version : "<<CV_VERSION<<endl;
    cout<<"Major version : "<<CV_MAJOR_VERSION<<endl;
    cout<<"Minor version : "<<CV_MINOR_VERSION<<endl;
    cout<<"Subminor version : "<<CV_SUBMINOR_VERSION<<endl;
    return 0;
}
