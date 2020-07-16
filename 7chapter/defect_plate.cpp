//
//  defect_plate.cpp
//  opencv_practice
//
//  Created by KimJunsik on 2019/12/22.
//  Copyright © 2019 KimJunsik. All rights reserved.
//

#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
    while(1)
    {
        int no;
        cout << "차량 영상 번호(0 : 종료) : ";
        cin >> no;
        if (no == 0) break;

        string fname = format("./7chapter/image/test_car/%02d.jpg", no);
        Mat image = imread(fname, 1);
        if (image.empty()) {
            cout << to_string(no) + "번 파일 영상이 없습니다. " << endl;
            continue;
        }

        Mat gray, sobel, th_img, morph;
        Mat kernel(5, 31, CV_8UC1, Scalar(1));
        cvtColor(image, gray, COLOR_BGR2GRAY);

        blur(gray, gray, Size(5, 5));
        Sobel(gray, gray, CV_8U, 1, 0, 3);

        threshold(gray, th_img, 120, 255, THRESH_BINARY);
        morphologyEx(th_img, morph, MORPH_CLOSE, kernel);

        imshow("image", image);
        imshow("binary image", th_img);
        imshow("open image", morph);
        waitKey();
    }
    return 0;
}
