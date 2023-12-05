cmake_minimum_required(VERSION 3.28)

project(lab1-1)
set(CMAKE_CXX_STANDARD 23)

file(GLOB sourcefiles "./*.cpp" "./.hpp")

add_executable(bout ${sourcefiles})