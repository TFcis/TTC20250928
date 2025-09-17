#include<bits/stdc++.h>
using namespace std;

pair<string,vector<int>> to_zero(string subs, int pos) {
    if(subs == "0000") return {"0000", {}};
    if(subs == "0001") return {"0001", {}};
    if(subs == "0010") return {"0000", {pos + 2}};
    if(subs == "0011") return {"0001", {pos + 1, pos + 2, pos + 1}};
    if(subs == "0100") return {"0000", {pos + 1}};
    if(subs == "0101") return {"0001", {pos + 1}};
    if(subs == "0110") return {"0110", {}};
    if(subs == "0111") return {"0001", {pos + 2, pos + 1}};
    if(subs == "1000") return {"1000", {}};
    if(subs == "1001") return {"1001", {}};
    if(subs == "1010") return {"1000", {pos + 2}};
    if(subs == "1011") return {"1011", {}};
    if(subs == "1100") return {"1000", {pos + 2, pos + 1, pos + 2}};
    if(subs == "1101") return {"1101", {}};
    if(subs == "1110") return {"1000", {pos + 1, pos + 2}};
    if(subs == "1111") return {"1101", {pos + 2}};
    return {"error", {-87}};
}

bool check(string s) {
    for(char& i : s) {
        if(i != '0') return 0;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<int> ans;
    int n;
    string s;
    cin >> n >> s;
    s = '0' + s + '0';
    for(int i = 0; i < s.length() - 3; i++) {
        auto [res, tmp] = to_zero(s.substr(i, 4), i);
        for(int& j : tmp) ans.push(j);
        for(int j = 0; j < 4; j++) s[i+j] = res[j];
    }
    for(int i = s.length() - 4; i >= 0; i--) {
        auto [res, tmp] = to_zero(s.substr(i, 4), i);
        for(int& j : tmp) ans.push(j);
        for(int j = 0; j < 4; j++) s[i+j] = res[j];
    }
    if(check(s)){
        cout << ans.size() << '\n';
        while(!ans.empty()) {
            cout << ans.top() <<'\n';
            ans.pop();
        }
    }else cout << -1 << '\n';
    return 0;
}
