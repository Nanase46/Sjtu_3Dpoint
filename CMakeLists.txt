cmake_minimum_required(VERSION 3.10)
project(sjtu_pointcloud1)

set(CMAKE_CXX_STANDARD 11)


cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

#OPENCV
find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

find_package(PCL 1.9 REQUIRED)


include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable(sjtu_pointcloud1 main.cpp)
target_link_libraries (sjtu_pointcloud1 ${PCL_LIBRARIES} ${Opencv_LIBS})