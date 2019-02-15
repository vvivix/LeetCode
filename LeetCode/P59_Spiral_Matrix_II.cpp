//
// Created by vvivi on 9/27/2018.
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
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> map(n, vector<int>(n, 0));

        int x = 0, y = 0;
        dir_t last_dir = RIGHT;

        auto dir_available = [&](dir_t dir) -> bool {
            bool b;
            switch (dir) {
                case RIGHT :
                    b = y + 1 < n && map[x][y + 1] == 0;
                    break;
                case DOWN:
                    b = x + 1 < n && map[x + 1][y] == 0;
                    break;
                case LEFT:
                    b = y - 1 >= 0 && map[x][y - 1] == 0;
                    break;
                case UP:
                    b = x - 1 >= 0 && map[x - 1][y] == 0;
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

        for (int i = 1; i <= n * n; i++) {
            map[x][y] = i;
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

        return map;
    }

};


TEST(SpiralMatrixII, case1) {
    Solution s;
    auto sm = s.generateMatrix(3);
    vector<vector<int>> expect = {{1, 2, 3},
                                  {8, 9, 4},
                                  {7, 6, 5}};
    ASSERT_EQ(sm, expect);
}

TEST(SpiralMatrixII, case2) {
    Solution s;
    auto sm = s.generateMatrix(1);
    vector<vector<int>> expect = {{1}};
    ASSERT_EQ(sm, expect);
}