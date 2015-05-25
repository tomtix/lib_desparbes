cmake_minimum_required(VERSION 2.8)
project(lib_desparbes)

if (NOT DEFINED CMAKE_ENABLE_C99)
  set(CMAKE_ENABLE_C99 "-std=gnu99")
endif(NOT DEFINED CMAKE_ENABLE_C99)
set(CMAKE_C_FLAGS "${CMAKE_ENABLE_C99} -Wall") 

enable_testing()
include_directories(include)
install(DIRECTORY include DESTINATION .)
add_subdirectory(src)
add_subdirectory(test)

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/lib_desparbes)
