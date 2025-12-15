cmake_minimum_required(VERSION 3.20)

project(QtImGui CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets OpenGL OpenGLWidgets)

add_subdirectory(ThirdParty/ImGui)
add_subdirectory(ThirdParty/ImGuizmo)
add_subdirectory(ThirdParty/ImNodes)
add_subdirectory(ThirdParty/ImPlot)
add_subdirectory(ThirdParty/ImPlot3D)

set(PROJECT_SOURCES
    QImGuiWidget.cpp
    QImGuiWidget.h
)

add_library(${PROJECT_NAME}
    ${PROJECT_SOURCES}
    ${ImGui_Source}
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    ImGui
    ImGuizmo
    ImNodes
    ImPlot
    ImPlot3D
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::OpenGL
    Qt6::OpenGLWidgets
)
