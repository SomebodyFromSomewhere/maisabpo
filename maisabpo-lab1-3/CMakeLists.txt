cmake_minimum_required(VERSION 3.28)

project(lab1-3)
set(CMAKE_CXX_STANDARD 23)

file(GLOB sourcefiles "./*.cpp" "./*.hpp")

add_executable(mmod ${sourcefiles})

# Связывание приложения с библиотекой mutl
target_link_libraries(mmod PRIVATE mutl)

add_custom_command(TARGET mmod POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:mutl> $<TARGET_FILE_DIR:mmod>)
