cmake_minimum_required(VERSION 3.16)

project(test)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hello_world test/hello_world.cpp)

find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable(hello_opencv test/hello_opencv.cpp)
add_executable(mask test/opencv2/mask.cpp)
add_executable(threshold test/opencv2/threshold.cpp)
add_executable(drawing test/opencv2/drawing.cpp)
add_executable(ROI test/opencv2/ROI.cpp)
add_executable(filter test/opencv2/filter.cpp)
add_executable(erode test/opencv2/erode.cpp)
add_executable(dilate test/opencv2/dilate.cpp)
add_executable(sobel test/opencv2/sobel.cpp)




target_link_libraries(hello_opencv ${OpenCV_LIBS})
target_link_libraries(mask ${OpenCV_LIBS})
target_link_libraries(threshold ${OpenCV_LIBS})
target_link_libraries(drawing ${OpenCV_LIBS})
target_link_libraries(ROI ${OpenCV_LIBS})
target_link_libraries(filter ${OpenCV_LIBS})
target_link_libraries(erode ${OpenCV_LIBS})
target_link_libraries(dilate ${OpenCV_LIBS})
target_link_libraries(sobel ${OpenCV_LIBS})