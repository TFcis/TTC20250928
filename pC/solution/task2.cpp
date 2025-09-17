#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	cin>>n>>s;
	if(n&1) cout<<n/2+(s[0] == '1')<<'\n';
	else cout<<n/2<<'\n';
	for(int i = 1; i<= n ;i++) {
		if(s[i-1] == '1') cout<<i<<'\n';
	}
	return 0;
}
