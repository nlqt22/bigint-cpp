## Search Insert Position

```c++
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() -1;
        while(l <= r) {
            int mid = (l+r)/2;
            if(nums[mid] == target){
                return mid;
            } 
            if(nums[mid] < target) {
                l = mid + 1;
            }
            if(nums[mid] > target) {
                r = mid - 1;
            }
        }
        return l;
    }
};
```

## Two Sum

```c++
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
```

## Valid Parenthenes

```c++
class Solution {
    public: 
        bool isValid(string s) {
            stack<char> st;
            for(char c : s) {
                if(c == '(' || c == '[' || c == '{') {
                    st.push(c);
                } else {
                    char x = st.top();
                    if(st.empty() || (x == '(' && c != ')') || (x == '{' && c != '}') || (x == '[' && c != ']')) {
                        return false;
                    }
                    st.pop();
                }
            }
            return st.empty();
        }
};
```

## Binary Search

```c++
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
```

## First Bad Version

```c++
class Solution {
    public: 
        int firstBadVersion(int n) {
            int l = 1, r = n, mid;
            while(l < r) {
                mid = (l+r)/2;
                if(!isBadVersion(mid)) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            return r;
        }
};
```

## Palindrome Number

```c++
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x % 10 == 0 && x != 0) return false;
        int rev = 0;
        while(x > rev) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        if(x == rev || x == rev/10) return true;
        else return false;
    }
};
```