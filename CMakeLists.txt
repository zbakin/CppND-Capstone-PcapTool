cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(PcapTool)

include_directories(include /usr/local/include/pcapplusplus)

file(GLOB SOURCES "src/*.cpp")
add_executable(PcapTool ${SOURCES})
set(CMAKE_PREFIX_PATH "/usr/local/lib")
target_link_libraries(PcapTool Pcap++ Packet++ Common++ pcap)

