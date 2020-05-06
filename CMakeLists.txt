cmake_minimum_required(VERSION 3.16)
project(DisplayProgram)

set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "/path/to/SFML-2.5.1/lib/cmake/SFML")
include_directories("/path/to/SFML-2.5.1/include")
include_directories("/path/to/rapidjson/include")

add_executable(DisplayProgram main.cpp PlayerEngine.cpp PlayerEngine.h Slide.cpp Slide.h)

find_package(SFML COMPONENTS graphics window REQUIRED)

target_link_libraries(DisplayProgram sfml-graphics)