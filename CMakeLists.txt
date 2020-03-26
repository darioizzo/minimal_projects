cmake_minimum_required(VERSION 2.8.12)
project(prova)
cmake_policy(SET CMP0057 NEW) 

find_package(pybind11 REQUIRED)
find_package(pagmo REQUIRED)

add_subdirectory(src)
