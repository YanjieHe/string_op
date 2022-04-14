cmake_minimum_required(VERSION 3.5)

project(string_op)

set(CMAKE_CXX_STANDARD 17)

include_directories(include/ libs/ test/)

file(GLOB SOURCES "src/*.cpp")
file(GLOB TESTS "test/*.cpp")

add_executable(string_op ${SOURCES} ${TESTS})