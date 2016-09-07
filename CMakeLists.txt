cmake_minimum_required(VERSION 2.8)
project(lib_desparbes C)

set(CMAKE_C_FLAGS "-std=gnu99 -Wall") 

enable_testing()
include_directories(include)
install(DIRECTORY include DESTINATION .)
add_subdirectory(src)
add_subdirectory(test)

