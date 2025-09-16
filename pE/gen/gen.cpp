#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	// about testlib, see https://codeforces.com/blog/entry/18291

	int t = atoi(argv[1]);
	int max_n = atoi(argv[2]);
	int max_m = atoi(argv[3]);
	long long max_nm = atol(argv[4]);
	cout << t << endl;
	for(int i = 0; i < t; i++) {
		int n = rnd.next(1, max_n);
		int m = rnd.next(1LL, min(max_nm / n, (long long) max_m));
		cout << n << " " << m << endl;
	}
	return 0;
}
