//
//  event_key.cpp
//  opencv_practice
//
//  Created by KimJunsik on 2019/11/20.
//  Copyright © 2019 KimJunsik. All rights reserved.
//

#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main()
{
    Mat image(200,300,CV_8U, Scalar(255));
    namedWindow("keybord event", WINDOW_AUTOSIZE);
    imshow("keybord event",image);
    
    while(1)
    {
        int key = waitKey(100);
        if(key == 27) break;
        
        switch(key)
        {
            case 'a': cout << "a키 입력" << endl; break;
            case 'b': cout << "b키 입력" << endl; break;
            case 0x41: cout << "A키 입력" << endl; break;
            case 66: cout << "B키 입력" << endl; break;
            case 0x25000: cout << "왼쪽 화살표 키 입력" << endl; break;
            case 0x26000: cout << "위쪽 화살표 키 입력" << endl; break;
            case 0x27000: cout << "오른쪽 화살표 키 입력" << endl; break;
            case 0x28000: cout << "아래쪽 화살표 키 입력" << endl; break;
        }
    }
    return 0;
}
