cmake_minimum_required(VERSION 3.14) 

project(build_libs LANGUAGES CXX)

add_subdirectory(glfw ${CMAKE_CURRENT_BINARY_DIR}/glfw)
add_subdirectory(spdlog ${CMAKE_CURRENT_BINARY_DIR}/spdlog)
add_subdirectory(glad ${CMAKE_CURRENT_BINARY_DIR}/glad)
add_subdirectory(json ${CMAKE_CURRENT_BINARY_DIR}/json)

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

add_library(build_libs STATIC
	   ${IMGUI_INCLUDES}
	   ${IMGUI_SOURCES}
)

target_include_directories(build_libs PUBLIC imgui)
target_link_libraries(build_libs PRIVATE glad glfw)