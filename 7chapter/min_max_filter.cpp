//
//  min_max_filter.cpp
//  opencv_practice
//
//  Created by KimJunsik on 2019/12/20.
//  Copyright © 2019 KimJunsik. All rights reserved.
//

#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void minMaxFilter(Mat img, Mat& dst, int size, int flag = 1)
{
    dst = Mat(img.size(), CV_8U, Scalar(0));
    Size msize(size, size);
    Point h_m = msize / 2;

    for (int i = h_m.y; i < img.rows - h_m.y; i++) {
        for (int j = h_m.x; j < img.cols - h_m.x; j++)
        {
            Point start = Point(j, i) - h_m;
            Rect roi(start, msize);
            Mat  mask = img(roi);

            double minVal, maxVal;
            minMaxLoc(mask, &minVal, &maxVal);
            dst.at<uchar>(i, j) = (flag) ? maxVal : minVal;
        }
    }
}

int main()
{
    Mat image = imread("./7chapter/image/min_max.jpg", 0);
    CV_Assert(image.data);

    Mat min_img, max_img;
    minMaxFilter(image, min_img, 5, 0);
    minMaxFilter(image, max_img, 5, 1);

    imshow("image", image);
    imshow("minFilter_img", min_img);
    imshow("maxFilter_img", max_img);
    waitKey();
    return 0;
}
