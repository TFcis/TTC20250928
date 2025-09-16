#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long a, b;
    bool ne = 0;
    cin >> n;
    if(n == 0) {
    	cout << "1 1\n";
	return;
    }
    if( n < 0 ) {
        n = -n;
        ne = 1;
    }
    for(int i = 1; i <= sqrt(n); i++) {
        if(n % i == 0) {
            a = (i + n / i) / 2;
            b = (n / i - i) / 2;
            if(a * a - b * b == n) {
                if(!ne) cout << a << " " << b << '\n';
                else cout << b << " " << a << '\n';
                return;
            }
        }
    }
    cout << -1 <<'\n'; 
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
