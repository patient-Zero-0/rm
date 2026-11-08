#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    cv::Mat src = cv::imread("test/img/lena.jpg");
    // 绘制圆形
    cv::circle(src, cv::Point(256,256), 100, cv::Scalar(0, 0, 255), 2);
    // 绘制线条
    cv::line(src, cv::Point(0, 0), cv::Point(512, 512), cv::Scalar(0, 255, 0), 2);
    // 绘制矩形
    cv::rectangle(src, cv::Point(100, 100), cv::Point(200, 200), cv::Scalar(255, 0, 0), 2);
    // 绘制文字 FONT_HERSHEY_SIMPLEX, FONT_HERSHEY_PLAIN, FONT_HERSHEY_DUPLEX
    cv::putText(src, "hellp opencv", cv::Point(100, 400), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(255, 255, 255), 2);// 1是缩放大小 最后的2是线条粗度

    cv::imshow("src", src);
    cv::waitKey();
}
