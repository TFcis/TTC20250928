#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, b;
    bool ne = 0;
    cin >> n;
    if( n < 0 ) {
        n = -n;
        ne = 1;
    }
    for(a = sqrt(n); a <= (n + 1) / 2; a++) {
        if(a * a - n < 0) continue;
        b = sqrt(a * a -n);
        if(b * b == a * a -n) {
            if(!ne) cout << a << " " << b << '\n';
            else cout << b << " " << a <<'\n';
            return;
        }
    }
    cout << -1 << '\n';
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
