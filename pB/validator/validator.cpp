#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
	registerValidation(argc, argv);
	// about testlib, see https://codeforces.com/blog/entry/18426

	int upper_t = atoi(argv[1]);
	int upper_n = atoi(argv[2]);
	int upper_sum_n = atoi(argv[3]);
	int upper_s = atoi(argv[4]);
	int t = inf.readInt(1, upper_t, "t");
	int p = inf.readInt(1, 2000000000,"p")
	inf.readEoln();
	if(upper_s == -1) {
		for(int i = 0; i < t; i++) {
			int sum_n = 0;
			int n = inf.readInt(1, upper_n, "n");
			sum_n += n;
			inf.readEoln();
			ensure(1 <= sum_n && sum_n <= upper_sum_n);
			for(int j = 0; j < n; j++) {
				int s = inf.readInt(-1, 1, "s");
				ensure(s == ((j & 1) ? -1: 1));
				if(j < n - 1) inf.readSpace();
				else inf.readEoln();
			}
		}
	}else{
		for(int i = 0; i < t; i++) {
			int sum_n = 0;
			int n = inf.readInt(1, upper_n, "n");
			sum_n += n;
			ensure(1 <= sum_n && sum_n <= upper_sum_n);
			inf.readEoln();
			for(int j = 0; j < n; j++) {
				int s = inf.readInt(-upper_s, upper_s, "s");
				if(j < n - 1) inf.readSpace();
				else inf.readEoln();
			}
		}
	}
	inf.readEof();
	return 0;
}
