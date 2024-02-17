cmake_minimum_required(VERSION 3.22.1)
project(lab_graph)

set(CMAKE_CXX_STANDARD 20)

file(GLOB RESOURCE CMAKE_CONFIGURE_DEPENDS
    ./*.cpp
    ./*.h
)

add_executable(MyLabGraph ${RESOURCE})