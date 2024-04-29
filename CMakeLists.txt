cmake_minimum_required(VERSION 3.16)
project(Hotel)

# Incluye el directorio raíz como un directorio de inclusión
include_directories(${CMAKE_SOURCE_DIR})

add_subdirectory(tests)
add_subdirectory(extern/googletest)
