cmake_minimum_required(VERSION 2.8)
project(CarEngineSimulation)

file(GLOB PROJECT_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_executable(${PROJECT_NAME} WIN32 ${PROJECT_SOURCES})