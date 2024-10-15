cmake_minimum_required(VERSION 3.16)

project(network VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(NETWORK_SOURCES
    network.cpp
)

add_library(network ${NETWORK_SOURCES})

target_include_directories(network PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/..)

