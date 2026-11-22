#include <iostream>
#include <opencv2/opencv.hpp>

/*
Canny边缘检测是⼀种⾮常流⾏的边缘检测算法，它分为五步
1. ⽤⾼斯滤波器平滑图像，去除噪声
2. 计算图像中每个像素点的梯度幅值和⽅向。⾸先通过Sobel算⼦计算⽔平⽅向和竖直⽅向的梯度，然后计算每个像素点的梯度幅值和⽅向
3. 应⽤⾮极⼤值抑制(NMS)算法消除边缘检测带来的杂散响应
4. 应⽤双阈值划分强边缘和弱边缘
5. 消除孤⽴的弱边缘在OpenCV中，可以⽤Canny()函数实现Canny边缘检测。

void cv::Canny(src, dst, threshold1, threshold2, apertureSize = 3, L2gradient = false)
threshold1: 第⼀个滞后阈值
threshold2: 第⼆个滞后阈值
apertureSize: Sobel算⼦的⼤⼩
*/

int main() {
    cv::Mat src = cv::imread("test/img/lena.jpg", cv::IMREAD_GRAYSCALE);
    cv::Mat dst_high, dst_low;

    //高阈值
    cv::Canny(src, dst_high, 100, 200);
    cv::Canny(src, dst_low, 50, 100);

    cv::imshow("src", src);
    cv::imshow("dst_high", dst_high);
    cv::imshow("dst_low", dst_low);
    cv::waitKey();


}




