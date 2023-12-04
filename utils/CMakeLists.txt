cmake_minimum_required(VERSION 3.28)

project(utils)

file(GLOB soourcefiles "./*.cpp" "./*.hpp")

add_library(utils ${soourcefiles})