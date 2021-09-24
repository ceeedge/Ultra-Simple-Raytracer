# Minimum required version
cmake_minimum_required(VERSION 3.21)

# not best practice, placeholder until cleanup
set(CMAKE_CXX_COMPILER "g++")

project(Ultra-Simple-Raytracer VERSION 0.0.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# add headers from other folders
add_executable(${PROJECT_NAME} main.cpp)




  