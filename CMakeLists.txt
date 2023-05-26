cmake_minimum_required(VERSION 3.16.3)
project(DroneMavLinkTransport)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS -pthread)

add_executable(HelloWorld helloworld.cpp)

add_executable(DroneMavLinkTransport main.cpp)
target_link_directories(DroneMavLinkTransport PUBLIC ${CMAKE_SOURCE_DIR}/lib)
target_link_libraries(DroneMavLinkTransport MavLinkCom)

add_executable(Transport main2.cpp)
target_link_directories(Transport PUBLIC ${CMAKE_SOURCE_DIR}/lib)
target_link_libraries(Transport MavLinkCom)
