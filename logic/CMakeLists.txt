cmake_minimum_required(VERSION 3.16)

project(logic VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LOGIC_SOURCES
    logic.cpp
)

add_library(logic ${LOGIC_SOURCES})

target_include_directories(logic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/../)

