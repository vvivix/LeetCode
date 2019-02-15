set(SRC
        P1_TowSum.cpp
        P7_ReverseInteger.cpp
        P21_Merge_Two_Sorted_Lists.cpp
        P58_Length_of_Last_Word.cpp
        P53_Maximum_Subarray.cpp
        P67_Add_Binary.cpp
        P59_Spiral_Matrix_II.cpp
        P54_Spiral_Matrix.cpp
        P102_Binary_Tree_Level_Order_Traversal.cpp
        P104_Maximum_Depth_of_Binary_Tree.cpp P20_ValidParentheses.cpp P9_Palindrome_Number.cpp P234_Palindrome_Linked_List.cpp 50_Pow_x_n.cpp 69_Sqrt_x.cpp P367_Valid_Perfect_Square.cpp 75_Sort_Colors.cpp P3_Longest_Substring_Without_Repeating_Characters.cpp)

add_executable(LeetCodePractice ${SRC})

target_link_libraries(LeetCodePractice gtest gtest_main)