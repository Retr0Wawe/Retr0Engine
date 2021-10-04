cmake_minimum_required(VERSION 3.14) 

project(build_libs LANGUAGES CXX)   #for build

add_subdirectory(glfw ${CMAKE_CURRENT_BINARY_DIR}/glfw)
add_subdirectory(spdlog ${CMAKE_CURRENT_BINARY_DIR}/spdlog)
add_subdirectory(glad ${CMAKE_CURRENT_BINARY_DIR}/glad)

project(Imgui LANGUAGES CXX)

set(IMGUI_INCLUDES
	imgui/imgui.h
	imgui/backends/imgui_impl_glfw.h
	imgui/backends/imgui_impl_opengl3.h
)

set(IMGUI_SOURCES
	imgui/imgui.cpp
	imgui/backends/imgui_impl_glfw.cpp
	imgui/backends/imgui_impl_opengl3.cpp
	imgui/imgui_draw.cpp
	imgui/imgui_tables.cpp
	imgui/imgui_widgets.cpp
	imgui/imgui_demo.cpp
)

add_library(Imgui STATIC
	   ${IMGUI_INCLUDES}
	   ${IMGUI_SOURCES}
)

target_include_directories(Imgui PUBLIC vendor)
target_include_directories(Imgui PUBLIC imgui)
target_link_libraries(Imgui PRIVATE glad glfw)