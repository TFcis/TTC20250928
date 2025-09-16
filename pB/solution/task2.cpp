#include<bits/stdc++.h>
using namespace std;

string to_string(__int128 val) {
    string output = "";
    while(val) {
        output += val % 10 + '0';
        val /= 10;
    }
    reverse(output.begin(), output.end());
    return output;
}

void solve() {
    int n, k;
    __int128 ans;
    cin >> n;
    for(int i = 0; i < n ; i++) cin >> k;
    ans = (__int128)1 << (n - 1);
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
