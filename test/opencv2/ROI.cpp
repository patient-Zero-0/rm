#include <iostream>
#include <opencv2/opencv.hpp>

/*
感兴趣区域
ROI 
有时，我们只对⼀幅图像的部分区域感兴趣，⽽原图像⼜⾮常巨⼤，如果处理整个图像会⾮常耗时，因此，
我们希望从原始图像中截取部分图像后再进⾏处理。我们将这个区域称为感兴趣区域
(Region of Interest, ROI)
*/

int main() {
    cv::Mat src = cv::imread("test/img/lena.jpg");
    cv::Mat roi = src(cv::Rect(100,100,200,200));
    cv::imshow("ROI", roi);
    cv::waitKey();
}