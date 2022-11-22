#include <bits/stdc++.h>
#include <stack>
using namespace std;

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

int main() {
    // freopen("INPUT.txt", "r", stdin);
}