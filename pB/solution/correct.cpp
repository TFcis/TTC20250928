#include<bits/stdc++.h>
using namespace std;

string to_string(__int128 val) {
    string output = "";
    bool ne = 0;
    if(val < (__int128) 0){
        ne = 1;
        val = -val;
    }
    while(val) {
        output += val % 10 + '0';
        val /= 10;
    }
    reverse(output.begin(), output.end());
    if(ne) output = '-' + output;
    return output;
}

void solve() {
    int n, k;
    __int128 ans = 0, last = 1;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> k;
        ans += last * k * (i & 1 ? 1 : -1);
        last = last * (n - i) / i;
    }
    cout << to_string(ans) << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
