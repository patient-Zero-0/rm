#include <iostream>
#include <opencv2/opencv.hpp>

/*
Sobel
算⼦是⼀个设计好的卷积核，⽤来检测图像中的⽔平和垂直边缘。它的数学表达式如下,其中Gx⽤来提取⽔平⽅向的边缘，Gy⽤来提取竖直⽅向的边缘：
     | -1  0  1  |
Gx = | -2  0  2  |
     | -1  0  1  |

     | -1  -2  -1 |
Gy = |  0   0   0 |
     |  1   2   1 |

*/

int main() {
    cv::Mat src = cv::imread("test/img/lena.jpg", cv::IMREAD_GRAYSCALE);
    cv::Mat dst;

    cv::Mat sobel_x = (cv::Mat_<float>(3, 3) <<
    -1, 0, 1,
    -2, 0, 2,
    -1, 0, 1);

    cv::Mat sobel_y = (cv::Mat_<float>(3, 3) <<
    -1, -2, -1,
    0, 0, 0,
    1, 2, 1);

    cv::Mat dst_x, dst_y;
    cv::filter2D(src, dst_x, -1, sobel_x);
    cv::filter2D(src, dst_y, -1, sobel_y);

    cv::imshow("src", src);
    cv::imshow("dst_x", dst_x);
    cv::imshow("dst_y", dst_y);
    cv::waitKey();

}