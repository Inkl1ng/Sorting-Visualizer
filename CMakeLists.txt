cmake_minimum_required(VERSION 3.29)

project(Sorting-Visualizer CXX)
set(CMAKE_CXX_STANDARD 20)

find_package(raylib CONFIG REQUIRED)

add_executable(Sorting-Visualizer "src/main.cpp")

target_link_libraries(Sorting-Visualizer PRIVATE raylib)