#include <gtest/gtest.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
#if 0 // hash map solution.
    int singleNumber(vector<int>& nums) {
        std::unordered_map<int, int> map;
        for (auto v : nums) {
            map[v]++;
        }
        for (auto v : nums) {
            if (map[v] == 1)
                return v;
        }
        return 0;
    }
#else // another cool solution.
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (auto &v : nums) {
            ans ^= v;
        }
        return ans;
    }
#endif
};

TEST(P136, Case_1) {
    vector<int> input{2,2,1};
    Solution s;
    ASSERT_EQ(s.singleNumber(input), 1);
}

TEST(P136, Case_2) {
    vector<int> input{4,1,2,1,2};
    Solution s;
    ASSERT_EQ(s.singleNumber(input), 4);
}
