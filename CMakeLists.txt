cmake_minimum_required(VERSION 3.23)
project(Lab5ISRPO)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(calc)

enable_testing()
add_subdirectory(tests)