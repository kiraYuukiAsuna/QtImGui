cmake_minimum_required(VERSION 3.20)

project(ImGui CXX)

set(PROJECT_SOURCE
    imconfig.h
    imgui_demo.cpp
    imgui_draw.cpp
    imgui_internal.h
    imgui_tables.cpp
    imgui_widgets.cpp
    imgui.cpp
    imgui.h
    imstb_rectpack.h
    imstb_textedit.h
    imstb_truetype.h
)

add_library(${PROJECT_NAME} ${PROJECT_SOURCE})
