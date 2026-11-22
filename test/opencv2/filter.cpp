#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    cv::Mat src = cv::imread("test/img/lena.jpg");
    cv::Mat dst;
    // 均值滤波器
    /*
    ones(行数, 列数, 数据类型)：定义一个全为1的3*3矩阵，数据类型为32位的浮点型，再整体除以9，
    filter2D(src, dst ,输出图像的深度, kernel卷积核), -1表示图像保持和原图像同一数据类型
    */
    cv::Mat kernel = cv::Mat::ones(3, 3, CV_32F) / 9;
    cv::filter2D(src, dst, -1, kernel);
    cv::imshow("dst", dst);
    cv::waitKey();

    /*
    常⻅的图像滤波器
    均值滤波
    均值滤波使⽤核内所有像素的平均值来代替中⼼像素的值，OpenCV提供了blur()函数实现图像的均值滤波
    void cv::blur(src, dst, ksize, anchor = Point(-1,-1), borderType = BORDER_DEFAULT)
    ksize: 卷积核的⼤⼩，必须是奇数

    中值滤波
    中值滤波使⽤核内所有像素的中值来代替中⼼像素的值，OpenCV提供了medianBlur()函数实现图像的中值滤波。中值滤波在椒盐噪声的去除中效果较好
    void cv::medianBlur(src, dst, ksize)

    ⾼斯滤波
    ⾼斯滤波使⽤⾼斯函数的值来代替中⼼像素的值，OpenCV提供了GaussianBlur()函数实现图像的⾼斯滤波。⾼斯滤波在⾼斯噪声的去除中效果较好
    sigmaX: ⾼斯核在x⽅向上的标准差，如果为0，则根据ksize⾃动计算
    

    这些滤波器的效果图都是能有效去除图像噪声，但会使图像变得模糊
    */


}