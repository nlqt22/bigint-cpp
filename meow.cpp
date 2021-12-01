#include <bits/stdc++.h>
using namespace std;

typedef string bigInt;

int cmp(bigInt a, bigInt b) {
    while(a.length() < b.length()) a = "0" + a;
    while(b.length() < a.length()) b = "0" + b;
    if(a == b) return 0;
    if(a > b)  return 1;
    return -1;
}

bigInt add(bigInt a, bigInt b) {
    bigInt res = "";
    int cr = 0, s;
    while(a.length() < b.length()) a = "0" + a;
    while(b.length() < a.length()) b = "0" + b;
    for(int i = a.length()-1; i >= 0; --i) {
        s = a[i] - '0' + b[i] - '0' + cr;
        cr = s / 10;
        res = (char)(s % 10 + '0') + res;
    }
    if(cr > 0) res = "1" + res;
    return res;
}

/* DK: a >= b */
bigInt sub(bigInt a, bigInt b) {
    bigInt res = "";
    int br = 0, s;
    while(a.length() < b.length()) a = "0" + a;
    while(b.length() < a.length()) b = "0" + b;
    for(int i = a.length()-1; i >= 0; --i) {
        s = a[i] - b[i] - br;
        if(s < 0) {
            s += 10;
            br = 1;
        } else br = 0;
        res = (char)(s % 10 + '0') + res;
    }
    while(res.length() > 1 && res[0] == '0') res.erase(0, 1);
    return res;
}

bigInt mul(bigInt a, bigInt b) {
    int m = -1;
    bigInt s = "", tmp;
    for(int i = a.length()-1; i >= 0; --i) {
        m++;
        tmp = "";
        for(int j = 0; j < (int)(a[i]-'0'); ++j) tmp = add(tmp, b);
        for(int j = 0; j < m; ++j) tmp += "0";
        s = add(tmp, s);
    }
    return s;
}

bigInt div(bigInt a, bigInt b) {
    bigInt res = "", h = "";
    long long k = 1;
    bigInt kb[11]; kb[0] = "0";
    for(int i = 1; i <= 10; ++i) kb[i] = add(kb[i-1], b);
    for(int i = 0; i < a.length(); ++i) {
        h = h + a[i];
        k = 1;
        while(cmp(h, kb[k]) != -1) ++k;
        res = res + (char)(k-1+48);
        h = sub(h, kb[k-1]);
    }
    while(res.length() > 1 && res[0] == '0') res.erase(0, 1);
    return res;
}

int main() {
    /* Your code here ! */
    
}