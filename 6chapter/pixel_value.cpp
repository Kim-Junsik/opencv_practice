//
//  pixel_value.cpp
//  opencv_practice
//
//  Created by KimJunsik on 2019/12/11.
//  Copyright © 2019 KimJunsik. All rights reserved.
//

#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
    Mat image = imread("./6chapter/image/pixel_test.jpg", IMREAD_GRAYSCALE);
    if (image.empty())
    {
        cout << "image is empty." << endl;
        exit(1);
    }

    Rect roi(135, 95, 20, 15);
    Mat roi_img = image(roi);
    cout << "[roi_img] =" << endl;

    for (int i = 0; i < roi_img.rows; i++){
        for (int j = 0; j < roi_img.cols; j++)
        {
            cout.width(5);
            cout << (int)roi_img.at<uchar>(i, j);
        }
        cout << endl;
    }
    //cout << roi_img << endl << endl;

    rectangle(image, roi, Scalar(255), 1);
    imshow("image", image);
    waitKey();
    return 0;
}
