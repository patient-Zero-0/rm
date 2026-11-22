#include <iostream>
#include <opencv2/opencv.hpp>

/*
膨胀与腐蚀相反，膨胀可以让图像变胖，可以⽤来填充图像中的空洞。
OpenCV提供了dilate()函数实现膨胀操作。

void cv::dilate(src, dst, kernel, anchor = Point(-1,-1), iterations = 1, borderType = BORDER_CONSTANT, borderValue = morphologyDefaultBorderValue())
*/


/*
开运算和闭运算

开运算=先腐蚀再膨胀。能够消除⼩的⼲扰块，将⼀些连通区域分割开。
闭运算=先膨胀再腐蚀。能够填充⼩的孔洞
在OpenCV中，可以⽤morphologyEx()函数实现开运算和闭运算

void cv::morphologyEx(src, dst, op, kernel, anchor = Point(-1,-1), iterations = 1, borderType = BORDER_CONSTANT, borderValue = morphologyDefaultBorderValue())
op: 操作类型，可取值为MORPH_OPEN, MORPH_CLOSE等
kernel: 结构元素

*/


int main() {
    cv::Mat src = cv::imread("test/img/erode_test.png", cv::IMREAD_GRAYSCALE);
    cv::threshold(src, src, 100, 255, cv::THRESH_BINARY);
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Point(3, 3));
    cv::Mat dst;

    cv::morphologyEx(src, dst, cv::MORPH_CLOSE, kernel, cv::Point(-1, -1), 3);

    cv::imshow("src", src);
    cv::imshow("dst", dst);
    cv::waitKey();
}
