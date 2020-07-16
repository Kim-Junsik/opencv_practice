//
//  scaling.cpp
//  opencv_practice
//
//  Created by KimJunsik on 2019/12/22.
//  Copyright © 2019 KimJunsik. All rights reserved.
//

#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void scaling(Mat  img, Mat& dst, Size size)            // 크기 변경 함수
{
    dst = Mat(size, img.type(), Scalar(0));                // 목적영상 생성
    double ratioY = (double)size.height / img.rows;    // 세로 변경 비율
    double ratioX = (double)size.width / img.cols;        // 가로 변경 비율

    for (int i = 0; i < img.rows; i++) {                // 입력영상 순회 – 순방향 사상
        for (int j = 0; j < img.cols; j++)
        {
            int x = (int)(j * ratioX);
            int y = (int)(i * ratioY);
            dst.at<uchar>(y, x) = img.at<uchar>(i, j);
        }
    }
}

int main()
{
    Mat image = imread("./8chapter/image/scaling_test.jpg", 0);
    CV_Assert(image.data);

    Mat dst1, dst2;
    scaling(image, dst1, Size(150, 200));        // 크기변경 수행 - 축소
    scaling(image, dst2, Size(300, 400));        // 크기변경 수행 - 확대

    namedWindow("resize_dst1-up", WINDOW_FREERATIO);
    imshow("image", image);
    imshow("dst1-up", dst1);
    imshow("dst2-down", dst2);
    imshow("resize_dst1-up", dst1);
    resizeWindow("resize_dst1-up", 500, 500);        // 윈도우 크기 확장
    waitKey();
    return 0;
}
