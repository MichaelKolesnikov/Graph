cmake_minimum_required(VERSION 3.21)

project(GraphProject VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Graph SHARED
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Graph/Graph/Graph.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Graph/GraphContainerManager/AdjacencyListContainerManager.cpp
)

target_include_directories(Graph PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(GraphExecutable main.cpp)
target_link_libraries(GraphExecutable PRIVATE Graph)
