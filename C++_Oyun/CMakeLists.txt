cmake_minimum_required(VERSION 3.27)
project(untitled3)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled3 main.cpp
        Ship.cpp
        Ship.h
        FastShip.cpp
        FastShip.h
        StrongShip.cpp
        StrongShip.h
        NormalShip.cpp
        NormalShip.h
)
