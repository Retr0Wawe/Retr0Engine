cmake_minimum_required(VERSION 3.14) 

project(Retr0EngineCore LANGUAGES CXX)

set(PUBLIC_INCLUDES
	includes/Application.hpp
	includes/Log.hpp
	includes/Callback.hpp
	)

set(PRIVATE_INCLUDES
	includes/private_includes/Window.hpp
    )

set(PRIVATE_SOURCES
	src/Application.cpp
	src/Window.cpp
	src/Callback.cpp
	)

set(CMAKE_CXX_STANDARD 17)

add_library(${PROJECT_NAME} STATIC
	${PUBLIC_INCLUDES}
	${PRIVATE_SOURCES}
	${PRIVATE_INCLUDES}
)

target_include_directories(${PROJECT_NAME} PRIVATE includes/private_includes)
target_include_directories(${PROJECT_NAME} PUBLIC includes)
target_include_directories(${PROJECT_NAME} PRIVATE src)

add_subdirectory(../../vendor/glfw ${CMAKE_CURRENT_BINARY_DIR}/glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

add_subdirectory(../../vendor/spdlog ${CMAKE_CURRENT_BINARY_DIR}/spdlog)
target_link_libraries(${PROJECT_NAME} PRIVATE spdlog)

add_subdirectory(../../vendor/glad ${CMAKE_CURRENT_BINARY_DIR}/glad)
target_link_libraries(${PROJECT_NAME} PRIVATE glad)

set(IMGUI_INCLUDES
	../../vendor/imgui/imgui.h
	../../vendor/imgui/backends/imgui_impl_glfw.h
	../../vendor/imgui/backends/imgui_impl_opengl3.h
)

set(IMGUI_SOURCES
	../../vendor/imgui/imgui.cpp
	../../vendor/imgui/backends/imgui_impl_glfw.cpp
	../../vendor/imgui/backends/imgui_impl_opengl3.cpp
	../../vendor/imgui/imgui_draw.cpp
	../../vendor/imgui/imgui_tables.cpp
	../../vendor/imgui/imgui_widgets.cpp
	../../vendor/imgui/imgui_demo.cpp
)

add_library(Imgui STATIC
			${IMGUI_INCLUDES}
			${IMGUI_SOURCES}
)

target_include_directories(Imgui PUBLIC ../../vendor)
target_include_directories(Imgui PUBLIC ../../vendor/imgui)
target_link_libraries(Imgui PRIVATE glad glfw)

target_link_libraries(${PROJECT_NAME} PRIVATE Imgui)