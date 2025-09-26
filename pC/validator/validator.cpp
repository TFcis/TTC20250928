#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
	registerValidation(argc, argv);
	// about testlib, see https://codeforces.com/blog/entry/18426

	int max_n = atoi(argv[1]);
	int sigma_max_n = 1000000;
	int max_t = 500000, sum_n = 0;
	bool diff = atoi(argv[2]);
	int t = inf.readInt(1, max_t, "t");
	inf.readEoln();
	while(t--){
		int n = inf.readInt(2, max_n, "n");
		sum_n += n;
		ensure(sum_n <= sigma_max_n);
		inf.readEoln();
		if(diff) {
			string s = "";
			for(int i = 0; i < n; i++) {
				char c = inf.readChar() - '0';
				s += c;
			}
			for(int i = 1; i < n - 1; i++) {
				ensure(s[i-1] != s[i] && s[i] != s[i+1]);
			}
		}else{
			for(int i = 0; i < n; i++) {
				int c = inf.readChar() - '0';
				ensure(c == 0 || c == 1);
			}
		}
		inf.readEoln();
	}
	inf.readEof();
	return 0;
}
