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
	
	if(max_n == 16) {
		if(num==1) {
			cout << (1<<15) <<'\n';
			for(int i = 0; i < (1<<15); i++) {
				cout << max_n << '\n';
				for(int j = 0; j < max_n; j++) {
					if((i>>j)&1) cout<<1;
					else cout<<0;
				}
				cout<<'\n';
			}
		}else{
			cout << (1<<15) << '\n';
			for(int i = (1<<15); i < (1<<16); i++) {
				cout << max_n << '\n';
				for(int j=0;j<max_n;j++) {
					if((i>>j)&1) cout<<1;
					else cout<<0;
				}
				cout<<'\n';
			}
		}
	}else if(max_n <= 15) {
		cout << (1<<max_n) << '\n';
		for(int i = 0; i < (1<<max_n); i++) {
			cout<<max_n<<'\n';
			for(int j = 0; j < max_n; j++) {
				if((i>>j)&1) cout<<1;
				else cout<<0;
			}
			cout<<'\n';
		}
	}else if(no) {
		cout<<1<<'\n';
		int n = rnd.next(max_n/2, max_n);
		n = min( n / 3 * 3 + 2, 999998);
		cout << n << '\n';
		for(int i = 0; i < n; i++) {
			if(i%3 == 2) cout << 0;
			else cout << 1;
		}
		cout << '\n';
	}else if(diff) {
		cout<<1<<'\n';
		int n = rnd.next(max_n/2, max_n);
		cout << n << '\n';
		int fir = rnd.next(0, 1);
		for(int i = 0; i < n; i++) {
			cout << fir;
			fir ^= 1;
		}
		cout << '\n';
	}else {
		cout << 1 <<'\n';
		int n = rnd.next(max_n/2, max_n);
		cout << n << '\n';
		for(int i = 0; i < n; i++) {
			cout << rnd.next(0, 1);
		}
		cout << '\n';
	}

	return 0;
}
