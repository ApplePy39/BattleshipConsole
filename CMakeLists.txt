cmake_minimum_required(VERSION 3.0.0)
project(BattleshipClone VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(BattleshipClone source/main.cpp
        source/main.cpp
        source/Render.cpp
        source/Render.h
        source/Globals.h
        source/Turn.cpp
        source/Turn.h
        source/Pieces.cpp
        source/Pieces.h
        source/Coordinates.cpp
        source/Coordinates.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
