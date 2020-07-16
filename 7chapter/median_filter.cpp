//
//  median_filter.cpp
//  opencv_practice
//
//  Created by KimJunsik on 2019/12/20.
//  Copyright © 2019 KimJunsik. All rights reserved.
//


#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void medianFilter(Mat img, Mat& dst, int size)
{
    dst = Mat(img.size(), CV_8U, Scalar(0));
    Size msize(size, size);
    Point h_m = msize / 2;

    for (int i = h_m.y; i < img.rows - h_m.y; i++){
        for (int j = h_m.x; j < img.cols - h_m.x; j++)
        {
            Point start = Point(j, i) - h_m;
            Rect roi(start, msize);
            Mat  mask;
            img(roi).copyTo(mask);
            
            Mat  one_row = mask.reshape(1, 1);
            cv::sort(one_row, one_row, SORT_EVERY_ROW);
            
            int medi_idx = (int) (one_row.total() / 2) ;
            dst.at<uchar>(i, j) = one_row.at<uchar>(medi_idx);
        }
    }
}

int main()
{
    Mat image = imread("./7chapter/image/median_test.jpg", IMREAD_COLOR);
    CV_Assert(image.data);

    Mat gray, med_img1, med_img2;
    cvtColor(image, gray, COLOR_RGB2GRAY);
    
    medianFilter(gray, med_img1, 5);
    medianBlur(gray, med_img2, 5);

    imshow("gray", gray);
    imshow("median-User", med_img1);
    imshow("median-OpenCV", med_img2);

    waitKey();
    return 0;
}
