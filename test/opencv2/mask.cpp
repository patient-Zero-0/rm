#include <opencv2/opencv.hpp>
#include <iostream>


int main()
{
    cv::Mat src = cv::imread("test/img/lena.jpg");
    cv::Mat mask = cv::Mat::zeros(src.size(), CV_8UC1);

    // 将掩码从(100,100)到(200,200)的区域置为255// ⼆进制中，255就是11111111
    cv::Rect rect(100, 100, 200, 200);
    mask(rect) = 255;// mark只认0和1~255的数，前者表示黑色，后者表示白色
    // 掩码与图像进⾏逻辑与运算，则掩码为255的区域保留，掩码为0的区域置为0
    cv::Mat dst;
    cv::bitwise_and(src, src, dst, mask);
    cv::imshow("dst", dst);
    cv::waitKey();
};