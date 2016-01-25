cmake_minimum_required(VERSION 2.8)
project( kalmanfilter )
find_package( OpenCV REQUIRED )
find_package(Eigen3 REQUIRED)
include_directories(${CURSES_INCLUDE_PATH})
include_directories(EIGEN3_INCLUDE_DIR)
add_executable(kalmanfilteropencv kalmanfilteropencv.cpp )
target_link_libraries( kalmanfilteropencv ${OpenCV_LIBS} )


