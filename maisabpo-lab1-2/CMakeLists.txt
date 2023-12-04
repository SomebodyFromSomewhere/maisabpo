cmake_minimum_required(VERSION 3.28)

project(lab1-2)

file(GLOB sourcefiles "./*.cpp" "./.hpp")

add_executable(binops ${sourcefiles})