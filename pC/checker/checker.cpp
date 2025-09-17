#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerTestlibCmd(argc, argv);
	// about testlib, see https://codeforces.com/blog/entry/18291
    	bool ok = true;
    	int n = ans.readInt();
	int len = inf.readInt();
	inf.readEoln();
	string anss = inf.readString();
	if(anss.back() == '\n') anss.pop_back();
        if(n == -1) {
            int b = ouf.readInt();
            if(b != -1) {
                ok = false;
            }
            ans.readEoln();
            ouf.readEoln();
        }else if(0 <= n && n <= 100000000){
            ans.readEoln();
	    string s(len, '0');
	    for(int i = 0; i < n; i++) {
	    	int p = ans.readInt();
		ans.readEoln();
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
    	quit(ok ? _ok : _wa);
	return 0;
}
