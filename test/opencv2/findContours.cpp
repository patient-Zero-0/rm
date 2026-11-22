#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>



/*
前⾯的Canny()函数只是检测出了图像的边缘，但并没有得到边缘的具体信息，
如果想要得到边缘的具体信息，也就是说得到每条边缘的每个点的坐标，可以使⽤findContours()函数。

void cv::findContours(image, contours, hierarchy, mode, method, offset = Point())
image: 输⼊图像，必须是⼆值图像
contours: 输出的轮廓(std::vector<cv::Point> )，每个轮廓由⼀系列点组成
hierarchy: 输出的轮廓的层次结构，std::vector<cv::Vec4i> 类型
mode: 轮廓检索模式
method: 轮廓近似⽅法

mode:
CHAIN_APPROX_NONE:保存物体边界上所有连续的轮廓点到contours向量内
CHAIN_APPROX_SIMPLE:仅保存轮廓的拐点信息，把所有轮廓拐点处的点保存

method:
RETR_EXTERNAL:只检索最外⾯的轮廓
RETR_LIST:检索所有的轮廓，并将其保存到⼀条链表当中
RETR_CCOMP:检索所有的轮廓，并将他们组织为两层：顶层是各部分的外部边界，第⼆层是内部边界
RETR_TREE:检索所有的轮廓，并重构嵌套轮廓的整个层次
*/

int main() {
    cv::Mat src = cv::imread("test/img/lena.jpg", cv::IMREAD_GRAYSCALE);
    cv::Mat dst;
    cv::Canny(src, dst, 100, 200);
    //轮廓
    std::vector<std::vector<cv::Point>> contours;
    //轮廓的层次结构
    std::vector<cv::Vec4i> hierarchy;
    //查找轮廓
    cv::findContours(dst, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);
    //绘制轮廓
    cv::Mat result;
    cv::cvtColor(src, result, cv::COLOR_GRAY2BGR);
    cv::drawContours(result, contours, -1, cv::Scalar(0, 255, 0), 2);

    cv::imshow("src", src);
    cv::imshow("dst", dst);
    cv::imshow("result", result);
    cv::waitKey();


}


