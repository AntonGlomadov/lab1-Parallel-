cmake_minimum_required(VERSION 3.17)
project(Lab1Paralel)

set(CMAKE_CXX_STANDARD 11)
add_executable(Lab1Paralel main.cpp)

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    target_link_libraries(Lab1Paralel PUBLIC OpenMP::OpenMP_CXX)
endif()