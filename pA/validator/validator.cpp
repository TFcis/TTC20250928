#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
	registerValidation(argc, argv);
	// about testlib, see https://codeforces.com/blog/entry/18426

	int upper_t = atoi(argv[1]);
	bool abs = atoi(argv[2]);
	long long upper_n = atoi(argv[3]);
	int t = inf.readInt(1, upper_t, "t");
	inf.readEoln();
	for(int i = 0; i < t; i++) {
		if(!abs) long long n = inf.readLong(0LL, upper_n, "n");
		else long long n = inf.readLong(-upper_n, upper_n, "n");
		inf.readEoln();
	}
	inf.readEof();
	return 0;
}
