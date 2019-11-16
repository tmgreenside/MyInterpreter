cmake_minimum_required(VERSION 3.10)
include(project.cmake)
project( ${PROJECT_NAME} )

# Boost dependencies
set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost COMPONENTS program_options) 
include_directories(${Boost_INCLUDE_DIRS}) 

include_directories(src/Interpreter)

file(GLOB SOURCES "src/Interpreter/*.cpp")

set (CMAKE_CXX_STANDARD 14)
add_executable( ${PROJECT_NAME} ./src/main.cpp )

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})