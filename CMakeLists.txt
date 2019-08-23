cmake_minimum_required(VERSION 3.1.0)

project(minesweeper)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


include_directories(include)

add_library(${PROJECT_NAME}
    include/Minesweeper.h
    src/Minesweeper.cpp
)

add_executable(play main.cpp)
target_link_libraries(play ${PROJECT_NAME})
