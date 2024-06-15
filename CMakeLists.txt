cmake_minimum_required(VERSION 3.27)
project(otus_cpp_basic_06homework)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(containers)
add_executable(homework6 main.cpp)
target_link_libraries(homework6 containers)
