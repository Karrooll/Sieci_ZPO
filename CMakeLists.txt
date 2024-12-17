cmake_minimum_required(VERSION 3.29)
project(Sieci_ZPO)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Sieci_ZPO
        helpers.h
        types.h
        storage_types.h
        package.h
        package.cpp
        nodes.cpp)
