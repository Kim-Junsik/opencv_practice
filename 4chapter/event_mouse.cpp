//
//  event_mouse.cpp
//  opencv_practice
//
//  Created by KimJunsik on 2019/11/20.
//  Copyright © 2019 KimJunsik. All rights reserved.
//

#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

void onMouse(int, int, int, int, void *);

int main()
{
    Mat image(200,300,CV_8U);
    image.setTo(255);
    imshow("mouse event 1",image);
    imshow("mouse event 2", image);
    
    setMouseCallback("mouse event 1", onMouse,0);
    waitKey(0);
    return 0;
}

void onMouse(int event, int x, int y, int flags, void *param)
{
    switch(event)
    {
        case EVENT_LBUTTONDOWN:
            cout << "왼쪽 버튼 누르기" << endl;
            break;
        case EVENT_RBUTTONDOWN:
            cout << "오른쪽 버튼 누르기" << endl;
            break;
        case EVENT_RBUTTONUP:
            cout << "오른쪽 버튼 떼기" << endl;
            break;
        case EVENT_LBUTTONDBLCLK:
            cout << "왼쪽 버튼 더블클릭" << endl;
            break;
    }
}
