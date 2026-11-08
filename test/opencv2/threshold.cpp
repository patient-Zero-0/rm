#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat src = cv::imread("test/img/lena.jpg", cv::IMREAD_GRAYSCALE);// cv::IMREAD_GRAYSCALE强制转成灰度图像
    cv::Mat dst;
    cv::threshold(src, dst,100, 255, cv::THRESH_BINARY);
    cv::imshow("dst", dst);
    cv::waitKey();
};
