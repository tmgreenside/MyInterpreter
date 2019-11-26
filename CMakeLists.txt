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
include_directories(src/error)

file(GLOB_RECURSE HEADERS "src/Interpreter/*.hpp" "src/error/*.h")
file(GLOB_RECURSE SOURCES "src/Interpreter/*.cpp")

set (INCLUDE_DIRS "")
foreach (_headerFile ${HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES INCLUDE_DIRS)

set (CMAKE_CXX_STANDARD 14)
add_executable( ${PROJECT_NAME} ./src/main.cpp ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${INCLUDE_DIRS} ${Boost_LIBRARIES})
