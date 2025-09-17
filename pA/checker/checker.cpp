#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerTestlibCmd(argc, argv);
	// about testlib, see https://codeforces.com/blog/entry/18291
    int t = inf.readInt();
    inf.readEoln();
	bool ok = true;
    for(int i = 0; i < t; i++) {
        long long n = inf.readLong();
        inf.readEoln();
        long long a = ouf.readLong();
        if(a == -1) {
            long long b = ans.readLong();
            if(b != -1) {
                ok = false;
                break;
            }
            ans.readEoln();
            ouf.readEoln();
        }else{
            ouf.readSpace();
            long long a2 = ouf.readLong();
            ouf.readEoln();
            ans.readLong();
            ans.readSpace();
            ans.readLong();
            ans.readEoln();
            if((__int128_t) a * a - (__int128_t) a2 * a2 != (__int128_t) n) {
                ok = false;
                break;
            }
        }
    }
    quit(ok ? _ok : _wa);
	return 0;
}
