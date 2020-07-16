//
//  remove_moire.cpp
//  opencv_practice
//
//  Created by KimJunsik on 2019/12/27.
//  Copyright © 2019 KimJunsik. All rights reserved.
//

#include "remove_moire.hpp"

Mat        image, dft_coef, spectrum_img;
int        radius, thres = 120;

void remove_moire(int  value, void*  userdata)
{
    Mat remove_mask, remv_dft_coef , spectrum_tmp;

    threshold(spectrum_img, remove_mask, thres, 255, THRESH_TOZERO_INV);
    threshold(remove_mask, remove_mask, 1, 255, THRESH_BINARY);
    circle(remove_mask, remove_mask.size() / 2, radius, Scalar(255), -1);

    dft_coef.copyTo(remv_dft_coef, remove_mask);
    log_mag(remv_dft_coef, spectrum_tmp);
    
    Rect img_rect(Point(0, 0), image.size());
    imshow("remove_moire", spectrum_tmp);
    imshow("result_image", IFFT(remv_dft_coef, image.size()));
}

int main()
{
    image = imread("./9chapter/image/mo3.jpg", 0);
    CV_Assert(image.data);

    FFT(image, dft_coef, spectrum_img);
    radius = dft_coef.rows / 4;

    imshow("image", image);
    imshow("remove_moire_image", spectrum_img);
    createTrackbar("radius", "remove_moire_image", &radius, 255, remove_moire);
    createTrackbar("threshold", "remove_moire_image", &thres , 255, remove_moire);
    waitKey();
    return 0;
}
