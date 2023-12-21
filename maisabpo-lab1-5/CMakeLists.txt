cmake_minimum_required(VERSION 3.25)

project(bnum)

file(GLOB sources "*.cpp" "*.hpp")

add_executable(bnum ${sources})
