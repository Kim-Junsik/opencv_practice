//
//  min_max_2.cpp
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
    Mat image = imread("./5chapter/image/minMax.jpg", IMREAD_GRAYSCALE);
    
    double minVal, maxVal;
    minMaxIdx(image, &minVal, &maxVal);

    double ratio = (maxVal - minVal)/ 255.0 ;
    Mat  dst = (image - minVal) / ratio;

    cout << "minVal  = " << minVal << endl;
    cout << "maxVal  = " << maxVal << endl;

    imshow("image", image);
    imshow("dst" , dst );
    waitKey();
    return 0;
}
