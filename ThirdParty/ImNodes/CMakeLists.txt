cmake_minimum_required(VERSION 3.20)

project(ImNodes CXX)

set(PROJECT_SOURCE
    imnodes_internal.h
    imnodes.cpp
    imnodes.h
)

add_library(${PROJECT_NAME} ${PROJECT_SOURCE})

target_include_directories(${PROJECT_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ../ImGui
)
