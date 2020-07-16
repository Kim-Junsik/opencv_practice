//
//  min_max.cpp
//  opencv_practice
//
//  Created by KimJunsik on 2019/12/09.
//  Copyright © 2019 KimJunsik. All rights reserved.
//

#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
    uchar data[] = {
        10, 200, 5, 7, 9,
        15, 35, 60, 80, 170,
        100, 2, 55, 37, 70
    };
    Mat  m1(3, 5, CV_8U, data);
    Mat  m2(3, 5, CV_8U, Scalar(50));
    Mat  m_min, m_max;
    double minVal, maxVal;
    int    minIdx[2] = {}, maxIdx[2] = {};
    Point  minLoc, maxLoc;

    min(m1, 30, m_min);
    max(m1, m2, m_max);
    minMaxIdx(m1, &minVal, &maxVal, minIdx, maxIdx);
    minMaxLoc(m1, 0, 0, &minLoc, &maxLoc);

    cout << "[m1] = " << endl << m1 << endl << endl;
    cout << "[m_min] = " << endl << m_min << endl;
    cout << "[m_max] = " << endl << m_max << endl << endl;
    
    cout << "m1 최솟값 : " << minVal << endl;
    cout << "    최솟값 좌표 : " << minIdx[1] << ", " << minIdx[0] << endl;

    cout << "m1 최댓값 : " << maxVal << endl;
    cout << "    최댓값 좌표 : " << maxIdx[1] << ", " << maxIdx[0] << endl << endl;

    cout << "m1 행렬 최솟값 좌표 : " << minLoc << endl;
    cout << "m1 행렬 최댓갑 좌표 :  " << maxLoc << endl;
    return 0;
}







