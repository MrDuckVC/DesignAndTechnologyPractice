cmake_minimum_required(VERSION 3.23)

set(project "minesweeper")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES Board.cpp Button.cpp minesweeper.cpp PlayState.cpp States.cpp Tile.cpp)

set(${project}_HEADERS Board.hpp Button.hpp minesweeper.hpp PlayState.hpp States.hpp Tile.hpp)

set(${project}_SOURCE_LIST ${${project}_SOURCES} ${${project}_HEADERS})

add_library(${project} STATIC ${${project}_SOURCE_LIST})

target_link_libraries(${project} PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)
