cmake_minimum_required(VERSION 3.10)
project(LeetCode)

set(CMAKE_CXX_STANDARD 17)

include_directories(3rd_party/googletest/include)
add_subdirectory (3rd_party/googletest)
add_subdirectory(LeetCode)

