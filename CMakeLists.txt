cmake_minimum_required(VERSION 2.8)

project(second)

set(second_src main.cpp CIntN.cpp operators.cpp AT.cpp)
set(second_hdr head.hpp CIntN.hpp AT.hpp CIntN0.hpp CIntN1.hpp factory.hpp)

add_executable(${PROJECT_NAME} ${second_src} ${second_hdr})

