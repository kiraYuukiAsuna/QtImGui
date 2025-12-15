cmake_minimum_required(VERSION 3.20)

project(ImGuizmo CXX)

set(PROJECT_SOURCE
    GraphEditor.cpp
    GraphEditor.h
    ImCurveEdit.cpp
    ImCurveEdit.h
    ImGradient.cpp
    ImGradient.h
    ImGuizmo.cpp
    ImGuizmo.h
    ImSequencer.cpp
    ImSequencer.h
    ImZoomSlider.h
)



add_library(${PROJECT_NAME} ${PROJECT_SOURCE})

target_include_directories(${PROJECT_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ../ImGui
)
