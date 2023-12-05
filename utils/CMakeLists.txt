cmake_minimum_required(VERSION 3.28)

project(mutl)
set(CMAKE_CXX_STANDARD 23)


set(UTILS_HEADERS mutl.hpp)
set(UTILS_SOURCES mutl.cpp)

# Определение макроса CONSOLE_UTILS_EXPORTS при построке библиотеки
add_library(mutl SHARED ${UTILS_SOURCES} ${UTILS_HEADERS})
target_compile_definitions(mutl PRIVATE CONSOLE_UTILS_EXPORTS)

# Путь к заголовкам для проекта, чтобы использовать #include "utils/mutl.hpp"
target_include_directories(mutl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})