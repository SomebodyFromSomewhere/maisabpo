cmake_minimum_required(VERSION 3.28)

project(bnum)

file(GLOB sources "*.cpp" "*.hpp")

add_executable(bnum ${sources})
