#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    long long ans = 1, p;
    cin >> n >> p;
    for(int i = 0; i < n; i++) cin >> k;
    for(int i = 1; i < n; i++) ans = (ans<<1)%p;
    cout << ans << '\n';
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
