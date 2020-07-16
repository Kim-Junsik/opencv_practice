//
//  read_pccamera.cpp
//  opencv_practice
//
//  Created by KimJunsik on 2019/11/27.
//  Copyright © 2019 KimJunsik. All rights reserved.
//

#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

void put_string(Mat &frame, string text, Point pt, int value)
{
    text += to_string(value);
    Point shade = pt + Point(2,2);
    int font = FONT_HERSHEY_SIMPLEX;
    putText(frame, text, shade, font, 0.7,  Scalar(0,0,0), 2);
    putText(frame, text, pt, font, 0.7, Scalar(120,200,90), 2);
}

int main()
{
    VideoCapture capture(0);
    if(!capture.isOpened())
    {
        cout << "camera is not opened" << endl;
        exit(1);
    }
    
    cout << "width " << capture.get(CAP_PROP_FRAME_WIDTH) << endl;
    cout << "height " << capture.get(CAP_PROP_FRAME_HEIGHT) << endl;
    cout << "exposure " << capture.get(CAP_PROP_EXPOSURE) << endl;
    cout << "brightness " << capture.get(CAP_PROP_BRIGHTNESS) << endl;
    
    for(;;)
    {
        Mat frame;
        capture.read(frame);
        
        put_string(frame, "EXPOS : ", Point(10,40), capture.get(CAP_PROP_EXPOSURE));
        imshow("camera view", frame);
        if(waitKey(30) >= 0) break;
    }
    
    return 0;
}
