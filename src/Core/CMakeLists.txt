cmake_minimum_required(VERSION 3.14) 

project(Retr0EngineCore LANGUAGES CXX)

set(PUBLIC_INCLUDES
	includes/Application.hpp
	includes/Log.hpp
	)

set(PRIVATE_INCLUDES
	includes/private_includes/Window.hpp
    )

set(PRIVATE_SOURCES
	src/Application.cpp
	src/Window.cpp
	)

set(CMAKE_CXX_STANDARD 14)

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

add_subdirectory(../../custom_glad ${CMAKE_CURRENT_BINARY_DIR}/custom_glad/glad)
target_link_libraries(${PROJECT_NAME} PRIVATE custom_glad)

