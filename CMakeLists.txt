cmake_minimum_required(VERSION 3.15)
project(ADT)

set(CMAKE_CXX_STANDARD 17)


include_directories(./src ./include)
add_executable(ADT src/main.cpp src/List.tpp include/ADT/List.h)