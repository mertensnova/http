project(http)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR}/includes)

set(SOURCES
    src/server.cpp
)

add_executable(http ${SOURCES})
cmake_minimum_required(VERSION 3.10)
