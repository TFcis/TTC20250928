#include<bits/stdc++.h>
using namespace std;

long long fpw(long long a, long long b, long long mod) {
	if(b == 0) return 1LL;
	long long re = fpw(a, b >> 1, mod);
	if(b & 1) return (__int128)re * re % mod * a % mod;
	return (__int128)re * re % mod;
}

void solve() {
	int n;
	long long p;
	cin >> n >> p;
	vector<long long> stair(n + 1), inv(n + 1);
	stair[0] = stair[1] = 1;
	inv[1] = inv[0] = 1;
	for(int i = 2; i <= n; i++) {
		stair[i] = 1LL * stair[i-1] * i % p;
	}
	inv[n] = fpw(stair[n], p - 2, p);
	for(int i = n - 1; i >= 2; i--) {
		inv[i] = (__int128)inv[i+1] * (i + 1) % p;
	}
	auto C = [&](long long n, long long m) -> long long {
		if(m > n) return 0;
		long long re = (__int128)stair[n] * inv[n-m] % p * inv[m] % p;
		return re;
	};
	long long ans = 0, s;
	for(int i = 0; i < n; i++) {
		cin >> s;
		ans += ((__int128)s * C(n-1,i) * ((i & 1) ? -1 : 1)) % p;
		ans %= p;
	}
	cout << (ans + p) % p << '\n';
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
