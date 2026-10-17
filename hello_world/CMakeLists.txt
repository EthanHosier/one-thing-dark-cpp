cmake_minimum_required(VERSION 4.3)
project(hello_world)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-Werror)

add_executable(hello_world main.cpp
        aNum/aNum.cpp)
