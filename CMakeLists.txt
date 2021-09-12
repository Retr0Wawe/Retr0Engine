cmake_minimum_required(VERSION 3.10)

project(Retr0Engine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src/Core) #add engine core for cmake compile

add_subdirectory(src/Editor) #add editor engine for cmake compile

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Retr0EngineEditor)
