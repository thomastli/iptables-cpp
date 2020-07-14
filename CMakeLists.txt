cmake_minimum_required(VERSION 3.0)
project(iptablescpp)
set(CMAKE_CXX_STANDARD 11)

add_executable($PROJECT_NAME main.cpp)

include_directories(include/iptables)