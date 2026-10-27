cmake_minimum_required(VERSION 4.3)
project(hello_world_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(hello_world_2 main.cpp)

#target_compile_options(hello_world_2 PRIVATE -fsanitize=thread)
#target_link_options(hello_world_2 PRIVATE -fsanitize=thread)

target_compile_options(hello_world_2 PRIVATE
        -fsanitize=address
        -fno-omit-frame-pointer
        -g
)
target_link_options(hello_world_2 PRIVATE -fsanitize=address)