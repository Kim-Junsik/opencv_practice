//
//  perspective_event.cpp
//  opencv_practice
//
//  Created by KimJunsik on 2019/12/24.
//  Copyright © 2019 KimJunsik. All rights reserved.
//

#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

Point2f  pts[4], small(10, 10);
Mat image;

void draw_rect(Mat image)
{
    Rect img_rect(Point(0, 0), image.size());
    for (int i = 0; i < 4; i++)
    {
        Rect rect(pts[i] - small, pts[i] + small);
        rect &= img_rect;
        image(rect) += Scalar(70, 70, 70);
        line(image, pts[i], pts[(i + 1) % 4], Scalar(255, 0, 255), 1);
        rectangle(image, rect, Scalar(255, 255, 0), 1);
    }
    imshow("select rect", image);
}

void warp(Mat image)
{
    Point2f dst_pts[4] =
    {
        Point2f(0, 0), Point2f(350, 0),
        Point2f(350, 350), Point2f(0, 350)
    };
    Mat dst;
    Mat perspect_mat = getPerspectiveTransform(pts, dst_pts);
    warpPerspective(image, dst, perspect_mat, Size(350, 350), INTER_CUBIC);
    imshow("ø÷∞Ó∫∏¡§", dst);
}

void  onMouse(int event, int x, int y, int flags, void*)
{
    Point curr_pt(x, y);
    static int check = -1;

    if (event == EVENT_LBUTTONDOWN)
    {
        for (int i = 0; i < 4; i++)
        {
            Rect rect(pts[i] - small, pts[i] + small);
            if (rect.contains(curr_pt))  check = i;
        }
    }
    if (event == EVENT_LBUTTONUP)
        check = -1;
    if (check >= 0)
    {
        pts[check] = curr_pt;
        draw_rect(image.clone());
        warp(image.clone());
    }
}

int main()
{
    image = imread("./8chapter/image/perspective_test.jpg", 1);
    CV_Assert(image.data);

    pts[0] = Point2f(100, 100);
    pts[1] = Point2f(300, 100);
    pts[2] = Point2f(300, 300);
    pts[3] = Point2f(100, 300);
    draw_rect(image.clone());
    setMouseCallback("select rect", onMouse, 0);
    waitKey(0);
    return 0;
}
