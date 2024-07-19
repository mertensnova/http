cmake_minimum_required(VERSION 3.10)
project(http)

# Set C++ standard requirements
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/includes)

# Find nlohmann_json package
find_package(nlohmann_json 3.2.0 REQUIRED)

# Define sources for the executable
set(SOURCES
    src/server.cpp
)

# Create executable target
add_executable(http ${SOURCES})

# Link nlohmann_json to the executable
target_link_libraries(http PRIVATE nlohmann_json::nlohmann_json)

