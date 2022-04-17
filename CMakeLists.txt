cmake_minimum_required(VERSION 3.22)
project(Chess)

set(CMAKE_CXX_STANDARD 23)

add_executable(Chess src/main.cpp src/game.cpp src/game.h)

include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Chess sfml-system sfml-window sfml-graphics)