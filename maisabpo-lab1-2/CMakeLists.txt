cmake_minimum_required(VERSION 3.25)

project(lab1-2)
set(CMAKE_CXX_STANDARD 23)

file(GLOB sourcefiles "./*.cpp" "./.hpp")

add_executable(binops ${sourcefiles})