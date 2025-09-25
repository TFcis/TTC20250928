#include <bits/stdc++.h>
#include "testlib.h"
#define i64 long long
#define u64 unsigned long long
#define i128 __int128_t
#define u128 __uint128_t
using namespace std;

i64 prime64(){
	random_device rd;
    mt19937_64 gen(rd());
    u64 l = 3ull, r = 2000000000ull, p; // 3, 2e9
    uniform_int_distribution<u64> dist(l, r);
    vector<u64> basenum{2ull, 325ull, 9375ull, 28178ull, 450775ull, 9780504ull, 1795265022ull};
    function<bool(u64)> check64 = [&basenum](u64 p){
		if(p<2) return false;
    	bool tmb;
    	u64 exp, tmp;
    	int num2;
    	function<u64(u128, u64, const u64&)> fsp = [](u128 a, u64 b, const u64& mod){
    		u128 tmp = 1ull;
	    	a%=(u128)mod;
			for(;b>0;b>>=1){
				if(b&1){
					tmp*=a;
					tmp%=(u128)mod;
				}
				a*=a;
				a%=(u128)mod;
			}
			return (u64)(tmp%(u128)mod);
	    };
    	for(auto& i:basenum){
    		if(i >= p) break;
    		tmb = 0;
    		exp = p-1;
    		num2 = 0;
    		for(; (exp&1)^1 ; exp>>=1) num2++;
    		tmp = fsp(i,exp,p);
    		if(tmp==1||tmp==p-1){
    			tmb = 1;
    			continue;
    		}
    		for(int i=1;i<num2;i++){
    			tmp = tmp*tmp%p;
    			if(tmp==p-1){
    				tmb = 1;
    				break;
    			}
    		}
    		if(!tmb) return false;
    	}
    	return true;
    };
    do p = dist(gen)|1ull;
   	while(check64(p));
	return p;
}

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	registerGen(argc, argv, 1);
	// about testlib, see https://codeforces.com/blog/entry/18291
	int t_max = atoi(argv[1]);
	int n_max = atoi(argv[2]);
	const int sigma_n_max = 2000000;
	int s_max = atoi(argv[3]);
	int n_sum = 0;
	int t = 0;
	vector<int> ns;
	while(true) {
		int n = rnd.next(1,n_max);
		n_sum += n;
		if(n_sum > sigma_n_max || t > t_max) break;
		t++;
		ns.push_back(n);
	}
	if(s_max != -1) {
		int t = ns.size();
		cout << t << endl;
		for(int i = 0; i < t; i++) {
			int n = ns[i];
			cout << n << " " << prime64() << endl;
			for (int j = 0; j < n; j++) {
				int s = rnd.next(-s_max, s_max);
				if(j < n - 1) cout << s << ' ';
				else cout << s << endl;
			}
		}
	}else{
		cout << 1999 << endl;
		for(int i = 1; i <= 1999; i++) {
			cout << i << " " << prime64() << endl;
			for(int j = 0; j < i; j++) {
				cout << ((j & 1) ? -1 : 1);
				if(j < i - 1) cout << ' ';
				else cout << endl;
			}
		}
	}
	return 0;
}
