#include <opencv2/opencv.hpp>
#include <iostream>

/*所谓掩码，就是⼀个只有0和1的矩阵，图像与掩码进⾏逻辑与、或运算，可以实现抠图、图像融合等功能。
在OpenCV中，像素逻辑运算函数有四个原型，分别代表逻辑与、或、异或、⾮运算。
void cv::bitwise_and(src1, src2, dst, mask)
void cv::bitwise_or(src1, src2, dst, mask)
void cv::bitwise_xor(src1, src2, dst, mask)
void cv::bitwise_nor(src, dst, mask)
*/



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