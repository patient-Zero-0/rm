#include <iostream>
#include <opencv2/opencv.hpp>

/*
图像的腐蚀过程与图像的卷积过程类似，都需要模板矩阵来控制运算的结果。腐蚀操作能够消除⼆值图像中⼀些细⼩的噪声，或者让⼀些连通区域分割开。
OpenCV提供了erode()函数实现腐蚀操作，在进⾏腐蚀操作前，还要使⽤getStructuringElement()函数创建⼀个结构元素(structuring element)

cv::Mat cv::getStructuringElement(shape, ksize, anchor = Point(-1,-1))
shape: 结构元素的形状，可取值为MORPH_RECT, MORPH_CROSS, MORPH_ELLIPSE
ksize: 结构元素的⼤⼩

void cv::erode(src, dst, kernel, anchor = Point(-1,-1), iterations = 1, borderType = BORDER_CONSTANT, borderValue = morphologyDefaultBorderValue())
kernel: 结构元素
iterations: 腐蚀的次数
*/

int main() {
    cv::Mat src = cv::imread("test/img/erode_test.png");
    cv::threshold(src, src, 100, 255, cv::THRESH_BINARY);
    cv::Mat dst;

    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));
    cv::erode(src, dst, kernel);
    cv::imshow("src", src);
    cv::imshow("dst", dst);
    cv::waitKey();
}

