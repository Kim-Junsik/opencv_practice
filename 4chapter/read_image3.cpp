//
//  read_image3.cpp
//  opencv_practice
//
//  Created by KimJunsik on 2019/11/27.
//  Copyright © 2019 KimJunsik. All rights reserved.
//

#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

void  print_matInfo(string name, Mat img)
{
    string str;
    int depth = img.depth();

    if (depth == CV_8U)     str = "CV_8U";
    else if (depth == CV_8S)     str = "CV_8S";
    else if (depth == CV_16U) str = "CV_16U";
    else if (depth == CV_16S)     str = "CV_16S";
    else if (depth == CV_32S) str = "CV_32S";
    else if (depth == CV_32F) str = "CV_32F";
    else if (depth == CV_64F) str = "CV_64F";

    cout << name;
    cout << format(": depth(%d) channels(%d) -> data: ", depth, img.channels());
    cout << str << "C" << img.channels() << endl;
}

int main()
{
    string filename1 = "./image/read_16.tif";
    string filename2 = "./image/read_32.tif";
    Mat color2unchanged1 = imread(filename1, IMREAD_UNCHANGED);
    Mat color2unchanged2 = imread(filename2, IMREAD_UNCHANGED);
    CV_Assert(color2unchanged1.data && color2unchanged2.data);
    
    Rect roi(100,100,1,1);
    cout << "16/32 bit image matrix coordi (100,100) pixel " <<endl;
    cout << "color2unchanged1 " << color2unchanged1(roi) << endl;
    cout << "color2unchanged2 " << color2unchanged2(roi) << endl;
    
    print_matInfo("color2unchanged1", color2unchanged1);
    print_matInfo("color2unchanged2", color2unchanged2);
    imshow("color2unchanged1", color2unchanged1);
    imshow("colorunchanged2", color2unchanged2);
    waitKey();
    return 0;
}
