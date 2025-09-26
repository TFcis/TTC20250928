#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerTestlibCmd(argc, argv);
	// about testlib, see https://codeforces.com/blog/entry/18291
    	bool ok = true;
	int t = inf.readInt();
	inf.readEoln();
	while(t--) {
		int n = ouf.readInt();
		ouf.readEoln();
		int b = ans.readInt();
		ans.readEoln();
		while(b>0){
			ans.readInt();
			ans.readEoln();
			b--;
		}
		int len = inf.readInt();
		inf.readEoln();
		string anss = inf.readToken();
		inf.readEoln();
        	if(n == -1) {
            		if(b != -1) {
                		ok = false;
				break;
            		}
        	}else if(0 <= n && n <= 100000000){
	    		string s(len, '0');
	    		for(int i = 0; i < n; i++) {
	    			int p = ouf.readInt();
				ouf.readEoln();
				if(p<=0 || p>len) {
					ok = false;
					break;
				}
				if(p == 1) {
					s[0] = !((bool)(s[1] - '0')) + '0';
				}else if(p == len) {
					s[len-1] = !((bool)(s[len-2] - '0')) + '0';
				}else if( len > p  && p > 1) {
					s[p-1] = !((bool)(s[p-2] - '0')^(bool)(s[p] - '0')) +'0';
				}else{
					ok = false;
					break;
				}
	    		}
	    		if(s != anss) ok = false;
        	}else ok = false;
		if(!ok) break;
	}
    	quit(ok ? _ok : _wa);
	return 0;
}
