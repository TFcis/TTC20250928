#include<bits/stdc++.h>
using namespace std;

void solve() {
    long long n, a, b;
    cin >> n;
    if(abs(n) % 2 == 1) {
        a = (n + 1) / 2;
        b = (n - 1) / 2;
    }else if(n % 4 == 0) {
        a = n / 4 + 1;
        b = n / 4 - 1;
    }else{
        cout<<-1<<'\n';
        return;
    }
    cout << a << " " << b <<'\n';
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
