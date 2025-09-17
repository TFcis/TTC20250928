#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	// about testlib, see https://codeforces.com/blog/entry/18291

	int max_n = atoi(argv[1]);
	bool no = atoi(argv[2]);
	int num = atoi(argv[3]);
	bool diff = atoi(argv[4]);
	
	if(max_n == 2) {
		cout << 2 << '\n';
		cout << bitset<2>(num) << '\n';
	}else if(max_n == 3) {
		cout << 3 << '\n';
		cout << bitset<3>(num) << '\n';
	}else if(max_n == 4) {
		cout << 4 << '\n';
		cout << bitset<4>(num) << '\n';
	}else if(no) {
		int n = rnd.next(2, max_n);
		n = min( n / 3 * 3 + 2, 999998);
		cout << n << '\n';
		for(int i = 0; i < n; i++) {
			if(i%3 == 2) cout << 0;
			else cout << 1;
		}
		cout << '\n';
	}else if(diff) {
		int n = rnd.next(2, max_n);
		cout << n << '\n';
		int fir = rnd.next(0, 1);
		for(int i = 0; i < n; i++) {
			cout << fir;
			fir ^= 1;
		}
		cout << '\n';
	}else {
		int n = rnd.next(2, max_n);
		cout << n << '\n';
		for(int i = 0; i < n; i++) {
			cout << rnd.next(0, 1);
		}
		cout << '\n';
	}

	return 0;
}
