//
//  example19.cpp
//  opencv_practice
//
//  Created by KimJunsik on 2019/11/20.
//  Copyright © 2019 KimJunsik. All rights reserved.
//

#include <opencv2/opencv.hPP>
using namespace std;
using namespace cv;
int main()
{
    Mat mat(10,15,CV_32S, Scalar(100));
    Range r1(1,5), r2(3,8), r3(3,7), r4(5,10), r5(5,9), r6(8,14);
    Mat two_mat = mat(r1,r2);
    two_mat.setTo(200);
    two_mat = mat(r5,r6);
    two_mat.setTo(300);
    two_mat = mat(r3,r4);
    two_mat.setTo(555);
    cout << mat << endl;
    return 0;
}
