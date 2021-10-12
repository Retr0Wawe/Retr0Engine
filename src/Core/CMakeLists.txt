cmake_minimum_required(VERSION 3.14) 

project(Retr0EngineCore LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(PUBLIC_INCLUDES
	includes/Application.hpp
	includes/Log.hpp
	includes/Callback.hpp
	includes/Shader.hpp
	includes/Window.hpp
	includes/utils/Retr0Str.hpp
	includes/utils/Retr0Ptr.hpp
)

set(PRIVATE_SOURCES
	src/Application.cpp
	src/Window.cpp
	src/Callback.cpp
	src/Shader.cpp
	src/utils/Retr0Str.cpp
	src/utils/Retr0Ptr.cpp
)

add_library(${PROJECT_NAME} STATIC
	${PUBLIC_INCLUDES}
	${PRIVATE_SOURCES}
)

target_include_directories(${PROJECT_NAME} PRIVATE includes/private_includes)
target_include_directories(${PROJECT_NAME} PUBLIC includes)
target_include_directories(${PROJECT_NAME} PRIVATE src)

target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

target_link_libraries(${PROJECT_NAME} PRIVATE spdlog)

target_link_libraries(${PROJECT_NAME} PRIVATE glad)

target_link_libraries(${PROJECT_NAME} PRIVATE Imgui)