cmake_minimum_required(VERSION 3.16)

project(phy_engine VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PHY_SOURCES
    phymath.cpp
    physics.cpp
)

add_library(phy_engine ${PHY_SOURCES}
    include/phymath.h
    include/physics.h
    include/object.h
    object.cpp)

target_include_directories(phy_engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/../)

