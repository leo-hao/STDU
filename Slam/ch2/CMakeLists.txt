cmake_minimum_required(VERSION 3.17)
project(ch2)

set(CMAKE_CXX_STANDARD 14)

add_executable(helloSlam main.cpp)
add_library(hello libHelloSLAM.cpp)
target_link_libraries(helloSlam hello)
