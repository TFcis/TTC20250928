#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	// about testlib, see https://codeforces.com/blog/entry/18291

	
	int t = atoi(argv[1]);
	bool abs = atoi(argv[2]);
	long long n = atoi(argv[3]);
	cout << t << endl;
	for(int i = 0; i < t - 1; i++) {
		if(!abs) cout << rnd.next(0LL, n);
		else cout << rnd.next(-n, n);
		cout << endl;
	}
	cout << 0 << endl;
	return 0;
}
