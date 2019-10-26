cmake_minimum_required(VERSION 2.6)
project(aquatic)

set(AQUATIC_WARNINGS "-Wall -Wextra -Wpedantic")

set(CMAKE_CXX_FLAGS "-std=c++17 ${AQUATIC_WARNINGS}")
set(CMAKE_C_FLAGS "-std=c11 ${AQUATIC_WARNINGS}")

file(GLOB AQUATIC_SOURCES "./*.cc" "./*.c")

add_executable(aquatic ${AQUATIC_SOURCES})

