cmake_minimum_required(VERSION 3.8)
project(Project3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    AdjList.cpp
    AdjList.h
    AdjMatrix.cpp
    AdjMatrix.h
    CMakeLists.txt
    main.cpp
    Prim.h
    RawColWeight.h)

add_executable(Project3 ${SOURCE_FILES})