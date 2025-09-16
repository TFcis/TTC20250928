#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	registerGen(argc, argv, 1);
	// about testlib, see https://codeforces.com/blog/entry/18291
	int t_max = atoi(argv[1]);
	int n_max = atoi(argv[2]);
	const int sigma_n_max = 2000000;
	int s_max = atoi(argv[3]);
	if(s_max != -1) {
		int t = t_max;
		cout << t << endl;
		for(int i = 0; i < t; i++) {
			int n = n_max;
			cout << n << endl;
			for (int j = 0; j < n; j++) {
				int s = rnd.next(-s_max, s_max);
				if(j < n - 1) cout << s << ' ';
				else cout << s << endl;
			}
		}
	}else{
		cout << 100 << endl;
		for(int i = 1; i <= 100; i++) {
			cout << i << endl;
			for(int j = 0; j < i; j++) {
				cout << ((j & 1) ? -1 : 1);
				if(j < i - 1) cout << ' ';
				else cout << endl;
			}
		}
	}
	return 0;
}
