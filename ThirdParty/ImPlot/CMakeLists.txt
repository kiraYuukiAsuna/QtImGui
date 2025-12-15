cmake_minimum_required(VERSION 3.20)

project(ImPlot CXX)

set(PROJECT_SOURCE
    implot_demo.cpp
    implot_internal.h
    implot_items.cpp
    implot.cpp
    implot.h
)

add_library(${PROJECT_NAME} ${PROJECT_SOURCE})

target_include_directories(${PROJECT_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ../ImGui
)
