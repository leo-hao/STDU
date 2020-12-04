cmake_minimum_required(VERSION 3.17)
PROJECT(example)

add_executable(coordinate coordinateTransform.cpp)
find_package(Pangolin REQUIRED)
include_directories(${Pangolin_INCLUDE_DIRS})
add_executable(plotTrajectory plotTrajectory.cpp)
target_link_libraries(plotTrajectory ${Pangolin_LIBRARIES})