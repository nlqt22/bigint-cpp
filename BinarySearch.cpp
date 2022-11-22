#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int lf = 0, rt = (int)nums.size()-1, mid;
            int kq = -1;

            while(lf <= rt) {
                mid = (lf + rt)/2;
                if(nums[mid] == target) {
                    kq = mid;
                    rt = mid - 1;
                }
                if(nums[mid] < target) lf = mid + 1;
                if(nums[mid] > target) rt = mid - 1;
            }
            return kq;
        }
};

int main() {
    freopen("INPUT.txt", "r", stdin);
    
    vector<int> nums;
    int target;
    while(cin >> target) {
        nums.push_back(target);
    }    
    nums.pop_back();

    Solution solve; cout << solve.search(nums, target);
    // cout << nums.size();
    // for (int x : nums) {
    //     cout << x << " ";
    // }
    // cout << "target = " << target;
}