#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> check;
        vector<int> ans(2);
        for(int i = 0; i < nums.size(); ++i) {
            int x = target - nums[i];
            if(check.find(x) != check.end()) {
                ans[0] = check[x];
                ans[1] = i;
                return ans;
            } else {
                check.insert({nums[i], i});
            }
        }
        return ans;
    }
};

int main() {
    // Blackpink in your area
}