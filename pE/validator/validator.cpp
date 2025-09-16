#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
	registerValidation(argc, argv);
	// about testlib, see https://codeforces.com/blog/entry/18426
	int max_t = atoi(argv[1]);
	int max_n = atoi(argv[2]);
	int max_m = atoi(argv[3]);
	long long max_nm = atol(argv[4]);
	int t = inf.readInt(1, max_t, "t");
	inf.readEoln();
	for(int i = 0; i < t; i++) {
		int n = inf.readInt(1, max_n, "n");
		inf.readSpace();
		int m = inf.readInt(1, max_m, "m");
		inf.readEoln();
		ensure(1LL <= (long long)n * (long long)m && (long long)n * (long long)m <= max_nm);
	}
	inf.readEof();
	return 0;
}
