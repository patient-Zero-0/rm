#include <iostream>
#include <filesystem>
#include <string_view>
#include <cstdlib>
#include <opencv2/opencv.hpp>
 
using namespace cv;
 
void print_usage(std::string_view prog_name) {
    std::cerr << "Usage: " << prog_name << " <image_path>\n";
}

int main(int argc, char* argv[]) {
    namespace fs = std::filesystem;
    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    fs::path image_path = argv[1];

    if(!fs::exists(image_path)) {
        std::cerr << "Error: File '" << image_path << "' does not exist.\n";
        return EXIT_FAILURE;                                                                                                                                            
    }

    Mat image = imread(image_path.string(), IMREAD_COLOR);
    if (!image.data) {
        std::cerr << "Error: Failed to load image data.\n";
        return EXIT_FAILURE;
    }

    namedWindow("Display Image", WINDOW_AUTOSIZE);
    imshow("Display Image", image);
    waitKey(0);
    return EXIT_SUCCESS;

}





