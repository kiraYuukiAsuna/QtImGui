cmake_minimum_required(VERSION 3.20)

project(ImPlot3D CXX)

set(PROJECT_SOURCE
    implot3d_demo.cpp
    implot3d_internal.h
    implot3d_items.cpp
    implot3d_meshes.cpp
    implot3d.cpp
    implot3d.h
)

add_library(${PROJECT_NAME} ${PROJECT_SOURCE})

target_include_directories(${PROJECT_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ../ImGui
)
