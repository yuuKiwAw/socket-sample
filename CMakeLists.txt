cmake_minimum_required(VERSION 3.0)
project(socket_sample VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
add_executable(server ./src/server.cpp)
add_executable(client ./src/client.cpp)

