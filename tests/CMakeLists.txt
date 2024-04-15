cmake_minimum_required(VERSION 3.16)
project(HotelTests)

# Configura las pruebas
add_executable(test_cliente test_cliente.cpp)
add_executable(test_habitacion test_habitacion.cpp)
add_executable(test_hotel test_hotel.cpp)

# Enlaza con Google Test
target_link_libraries(test_cliente PRIVATE GTest::gtest GTest::gtest_main)
target_link_libraries(test_habitacion PRIVATE GTest::gtest GTest::gtest_main)
target_link_libraries(test_hotel PRIVATE GTest::gtest GTest::gtest_main)

target_sources(test_cliente PRIVATE ${CMAKE_SOURCE_DIR}/cliente.cpp)
target_sources(test_habitacion PRIVATE ${CMAKE_SOURCE_DIR}/habitacion.cpp ${CMAKE_SOURCE_DIR}/cliente.cpp)
target_sources(test_hotel PRIVATE  ${CMAKE_SOURCE_DIR}/hotel.cpp ${CMAKE_SOURCE_DIR}/habitacion.cpp ${CMAKE_SOURCE_DIR}/cliente.cpp)