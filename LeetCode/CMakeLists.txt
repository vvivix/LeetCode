file(GLOB SRC *.cpp)
add_executable(LeetCodePractice ${SRC})
target_link_libraries(LeetCodePractice gtest gtest_main)