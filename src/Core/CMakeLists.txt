cmake_minimum_required(VERSION 3.14) 

project(Retr0EngineCore LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(UTILS_INCLUDES
	includes/utils/Retr0Str.hpp
	includes/utils/Retr0Ptr.hpp
)

set(UTILS_SOURCES
	src/utils/Retr0Str.cpp
)

set(PUBLIC_INCLUDES
	includes/Application.hpp
	includes/Log.hpp
	includes/Callback.hpp
	includes/Shader.hpp
	includes/Window.hpp
	includes/Utils.hpp
	includes/ImGuiLayer.hpp
	includes/VertexBuffer.hpp
	includes/Settings.hpp
)

set(PRIVATE_SOURCES
	src/Application.cpp
	src/Window.cpp
	src/Callback.cpp
	src/Shader.cpp
	src/ImGuiLayer.cpp
	src/VertexBuffer.cpp
	src/Settings.cpp
)

add_library(${PROJECT_NAME} STATIC
	${UTILS_INCLUDES}
	${UTILS_SOURCES}
	${PUBLIC_INCLUDES}
	${PRIVATE_SOURCES}
)

target_include_directories(${PROJECT_NAME} PRIVATE includes/private_includes)
target_include_directories(${PROJECT_NAME} PUBLIC includes)
target_include_directories(${PROJECT_NAME} PRIVATE src)
target_include_directories(${PROJECT_NAME} PUBLIC ../../vendor/json/single_include/nlohmann)

target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

target_link_libraries(${PROJECT_NAME} PRIVATE spdlog)

target_link_libraries(${PROJECT_NAME} PRIVATE glad)

target_link_libraries(${PROJECT_NAME} PRIVATE build_libs)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/build/Debug/shaders)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/shaders/fragment.txt ${CMAKE_BINARY_DIR}/build/Debug/shaders COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/shaders/vertex.txt ${CMAKE_BINARY_DIR}/build/Debug/shaders COPYONLY)