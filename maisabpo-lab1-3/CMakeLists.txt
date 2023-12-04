cmake_minimum_required(VERSION 3.28)

project(lab1-3)

file(GLOB sourcefiles "./*.cpp" "./.hpp")

add_executable(mmod ${sourcefiles})