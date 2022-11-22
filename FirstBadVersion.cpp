#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
    private:
        bool isBadVersion(int version) {
            return true;
        }
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

int main() {
    // freopen("INPUT.txt", "r", stdin);
}