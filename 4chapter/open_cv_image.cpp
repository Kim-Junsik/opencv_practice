//
//  open_cv_ex.cpp
//  openCV_install
//
//  Created by KimJunsik on 09/08/2019.
//  Copyright © 2019 KimJunsik. All rights reserved.
//

#include <opencv2/core.hpp>             // 이미지 저장시 사용하는 Mat클래스를 포함한 open_cv에서 사용하는 기본적인 자료구조와 함수들을 모아놓은 해더파일
#include <opencv2/imgcodecs.hpp>        // 이미지 파일을 읽어오는 함수와 저장하는 함수를 포함하는 해더파일
#include <opencv2/highgui.hpp>          // 인터페이스를 구현해 놓은 해더파일, 사용자의 입력을 받기 위해 대기하는 함수와 화면에 이미지를 보여주기 위한 함수 포함
#include <opencv2/imgproc.hpp>          // Canny함수를 사용하기 위해 추가한 해더파일
#include <opencv2/opencv.hpp>           // 하나의 해더파일의 포함으로 모두 할 수 있다.

#include <iostream>


using namespace cv;
using namespace std;            // cv와 std는 이름이 충돌 되는 경우가 없으므로 namespace를 사용해도 된다.

// main함수에 arguments를 넣어주면 terminal에서도 실행이 가능하다.
int main()
{
    // 이미지를 읽어 Mat객체를 반환, 두번째 매개변수는 int flags로 IMREAD_UNCHANGED, IMREAD_COLOR, IMREAD_GRAYSPACE를 주로 사용한다.
    // IMREAD_UNCHANGED     -->    알파채널을 포함시킨 컬러이미지를 리턴
    // IMREAD_COLOR         -->    알파채널을 포함시키지 않은 컬러이미지를 리턴
    // IMREAD_GRAYSPACE     -->    그레이 스케일 이미지로 리턴
//    Mat image = imread("/Users/kimjunsik/Desktop/test/openCV_install/openCV_install/minion.jpg", IMREAD_COLOR);
    Mat result_image;
    Mat image = imread("./minion.jpg", IMREAD_COLOR);
    
    if (image.empty())
    {
        cout << "Could not open or find the image" << endl;
        return -1;
    }
    
    // 이미지를 보여줄 윈도우 생성, 첫 매개변수는 윈도우 식별자인동시에 윈도우에 보여질 이름, 두 번째 매개변수는 윈도우 크기 설정
    // WINDOW_AUTOSIZE는 이미지의 크기에 맞추어 윈도우 생성 이미지의 크기가 만약 모니터보다 크다면 일부분만 보일 수 있다. 또한 사용자가 위도우의 크기를 조정할 수 없다.
    // WINDOW_NORMAL은 이미지가 클 경우 해상도 크기에 맞추어 윈도우의 이미지가 결정되며 사용자가 윈도우의 크기를 설정할 수 있다.
    // namedWindow함수는 생략이 가능하며 imshow함수만을 이용하여 실행이 가능하다
    // 만약 윈도우에 트랙바를 붙일 경우에는 namedWindow함수가 필요하며 imshow만을 호출하면 WINDOW_AUTOSIZE로 윈도우가 설정된다.
    namedWindow("Original", WINDOW_NORMAL);
    
    // Canny함수는 엣지를 검출하는 함수이다.
    // 첫번째 아규먼트 image는 입력 이미지이다.
    // 두번째 아규먼트 edges에 Canny 결과를 저장할 변수를 넣어준다.
    // 세번째, 네번째 아규먼트 threshold1, threshold2는 최소 스레숄드와 최대 스레숄드이다.
    // 다섯번째 아규먼트 apertureSize는 이미지 그레디언트를 구할때 사용하는 소벨 커널 크기이며, 디폴트는 3이다.
    // 여섯번째 아규먼트 L2gradient가 True이면 그레디언트 크기를 계산할 때 sqrt{(dI/dx)^2 + (dI/dy)^2}를 사용한다. False라면 근사값인 |dI/dx|+|dI/dy|를 사용하며, 디폴트값은 False이다.
    Canny(image, result_image, 50, 150);
    imshow("Original", image);                          // 첫 번쨰 매개변수로 지정된 윈도우에 두 번째 매개변수로 지정한 Mat객체에 저장된 이미지를 보여준다.
    imshow("result_Original", result_image);
    
    
    // 전체 화면으로 보이기 위해 화면 수정
    //namedWindow("aaa", WND_PROP_FULLSCREEN);
    //setWindowProperty("aaa", WND_PROP_FULLSCREEN, WINDOW_FULLSCREEN);
    //imshow("aaa", image);
    
    waitKey(5000);         // 키보드 입력이 들어올 때 까지 이미지를 보여주며 대기 --> 일정시간을 대기하게 하고 싶다면 0 대신 다른 값을 넣어주면된다. 단위는 ms이다.
    
}
