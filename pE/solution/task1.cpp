#include<bits/stdc++.h>
using namespace std;

vector<int> phi;

void Euler(const int& maxx) {
	vector<int> prime, sp(maxx+5, 0); // prime, small prime
	phi.resize(maxx+5,0);
	phi[1] = 1;
	for(int i = 2; i <= maxx; i++) {
		if(sp[i] == 0) {
			prime.push_back(i);
			phi[i] = i - 1;
			sp[i] = i;
		}
		for(int& j : prime) {
			if(i * j > maxx) break;
			sp[i*j] = j;
			if(j < sp[i]) phi[i*j] = phi[i] * phi[j];
			else{
				phi[i*j] = phi[i] * j;
				break;
			}
		}
	}
	return;
}

void solve() {
	int n,m;
	long long ans = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			ans += phi[gcd(i, j)];
		}
	}
	cout << ans << '\n';
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	Euler(1e6);
	cin>>t;
	while(t--) {
		solve();
	}
	return 0;
}

