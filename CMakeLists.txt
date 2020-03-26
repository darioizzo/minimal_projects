cmake_minimum_required(VERSION 3.8)
project(prova)
cmake_policy(SET CMP0057 NEW) 

find_package(pybind11 REQUIRED)
find_package(pagmo REQUIRED)

add_subdirectory(src)
