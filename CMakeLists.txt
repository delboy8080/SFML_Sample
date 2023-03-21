cmake_minimum_required(VERSION 3.21)
project(SFML_Sample)

set(CMAKE_CXX_STANDARD 11)

add_executable(SFML_Sample main.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR H:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(H:/SFML/include)
target_link_libraries(SFML_Sample sfml-system sfml-window sfml-graphics sfml-audio)