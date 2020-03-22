cmake_minimum_required(VERSION 3.5)
message(STATUS "Using CMake ${CMAKE_VERSION}")

project(TextAnalysis VERSION "${META_VERSION_STRING}" LANGUAGES CXX C)

add_executable(ta
    src/main.cpp
    src/TextAnalysis.cpp)

target_link_libraries(ta pthread)