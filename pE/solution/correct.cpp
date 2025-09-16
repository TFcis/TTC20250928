#include<bits/stdc++.h>
using namespace std;

vector<long long> prefix; // prefix of \phi \ast \mu

void Euler(const int& maxx) {
	vector<int> pam(maxx+5, 0), prime, sp(maxx+5, 0), spc(maxx+5, 0); // \phi \ast \mu, prime, small prime, small prime count
	prefix.resize(maxx+5,0);
	pam[1] = 1;
	for(int i = 2; i <= maxx; i++) {
		if(sp[i] == 0) {
			prime.push_back(i);
			pam[i] = i - 2;
			sp[i] = i;
			spc[i] = 1;
		}
		for(int& j : prime) {
			if(i * j > maxx) break;
			sp[i*j] = j;
			if(j < sp[i]) {
				pam[i*j] = pam[i] * pam[j];
				spc[i*j] = 1;
			}else{
				spc[i*j] = spc[i] + 1;
				if(spc[i] == 1 && pam[i] == 0) pam[i*j] = pam[i/j];
				else if(spc[i] == 1) pam[i*j] = pam[i] / (j - 2) * (j - 1) * (j - 1);
				else pam[i*j] = pam[i] * j;
				break;
			}
		}
	}
	for(int i = 1; i <= maxx; i++) {
		prefix[i] = pam[i] + prefix[i-1];
	}
	return;
}

void solve() {
	int n, m, r;
	long long ans = 0;
	cin >> n >> m;
	for(int i = 1; i <= min(n,m); i = r + 1) {
		r = min({n / (n / i), m / (m / i), n, m});
		ans += (prefix[r] - prefix[i-1]) * (n/i) * (m/i);
	}
	cout << ans <<'\n';
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	Euler(1e6);
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}

