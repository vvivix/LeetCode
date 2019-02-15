//
// Created by vvivi on 9/28/2018.
//
#include "gtest/gtest.h"

using namespace std;

/**
 *    y--->
 * x  (0,0) (0,1) ... (0,n)
 * |  (1,0) (1,1) ... (1,n)
 * |  ...
 * V  (n,0) (n,1) ... (n,n)
 */
class Solution {
    enum dir_t {
        RIGHT, DOWN, LEFT, UP
    };
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        auto h = matrix.size();
        if (h == 0) return vector<int>();

        auto w = matrix[0].size();
        if (w == 0) return vector<int>();

        vector<vector<bool>> flag_matrix (h, vector<bool>( w, true) );
        vector<int> order(matrix.size()*matrix[0].size());

        int x = 0, y = 0;
        dir_t last_dir = RIGHT;

        auto dir_available = [&](dir_t dir) -> bool {
            bool b;
            switch (dir) {
                case RIGHT :
                    b = y + 1 < w && flag_matrix[x][y + 1];
                    break;
                case DOWN:
                    b = x + 1 < h && flag_matrix[x + 1][y];
                    break;
                case LEFT:
                    b = y - 1 >= 0 && flag_matrix[x][y - 1];
                    break;
                case UP:
                    b = x - 1 >= 0 && flag_matrix[x - 1][y];
                    break;
            }
            return b;
        };

        auto move_to = [&](dir_t dir) {
            switch (dir) {
                case RIGHT:
                    y += 1;
                    break;
                case DOWN:
                    x += 1;
                    break;
                case LEFT:
                    y -= 1;
                    break;
                case UP :
                    x -= 1;
                    break;
            }
        };

        for (int i = 0; i < w * h; i++) {
            order[i] = matrix[x][y];
            flag_matrix[x][y] = false;
            if (dir_available(last_dir)) {
                move_to(last_dir);
                continue;
            }

            const dir_t order_list[4] = {RIGHT, DOWN, LEFT, UP};
            for (auto cur_dir : order_list) {
                if (dir_available(cur_dir)) {
                    last_dir = cur_dir;
                    break;
                }
            }
            move_to(last_dir);
        }

        return order;
    }
};


TEST(SpiralMatrix, case1) {
    Solution s;
    vector<vector<int>> input = {{1, 2, 3},
                                 {4, 5, 6},
                                 {7, 8, 9}};
    auto actual = s.spiralOrder(input);
    vector<int> expect{1,2,3,6,9,8,7,4,5};
    ASSERT_EQ(actual, expect);
}

TEST(SpiralMatrix, case2) {
    Solution s;
    vector<vector<int>> input = {{1}};
    auto actual = s.spiralOrder(input);
    vector<int> expect{1};
    ASSERT_EQ(actual, expect);
}

TEST(SpiralMatrix, case3) {
    Solution s;
    vector<vector<int>> input = {{1, 2, 3, 4},{5, 6, 7, 8},{9,10,11,12}};
    auto actual = s.spiralOrder(input);
    vector<int> expect{1,2,3,4,8,12,11,10,9,5,6,7};
    ASSERT_EQ(actual, expect);
}

TEST(SpiralMatrix, case4) {
    Solution s;
    vector<vector<int>> input = {{1, 2, 3, 4}};
    auto actual = s.spiralOrder(input);
    vector<int> expect{1,2,3,4};
    ASSERT_EQ(actual, expect);
}

TEST(SpiralMatrix, case5) {
    Solution s;
    vector<vector<int>> input = {{1}, {2}, {3}, {4}};
    auto actual = s.spiralOrder(input);
    vector<int> expect{1,2,3,4};
    ASSERT_EQ(actual, expect);
}

TEST(SpiralMatrix, case6) {
    Solution s;
    vector<vector<int>> input = {{}};
    auto actual = s.spiralOrder(input);
    vector<int> expect{};
    ASSERT_EQ(actual, expect);
}

TEST(SpiralMatrix, case7) {
    Solution s;
    vector<vector<int>> input = {};
    auto actual = s.spiralOrder(input);
    vector<int> expect{};
    ASSERT_EQ(actual, expect);
}

TEST(SpiralMatrix, case8) {
    Solution s;
    vector<vector<int>> input = {{2,5},{8,4},{0,-1}};
    auto actual = s.spiralOrder(input);
    vector<int> expect{2,5,4,-1,0,8};
    ASSERT_EQ(actual, expect);
}