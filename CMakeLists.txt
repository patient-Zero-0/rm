cmake_minimum_required(VERSION 3.16)

project(test)

add_executable(hello_world test/hello_world.cpp)



/*terminal 使用方法
mkdir build
cmake -B build
make -C build
./build/<build目录下的项目名>*/