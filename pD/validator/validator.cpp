#include <algorithm>
#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

/*
* 32bit
* 00000000000000000000000000 1 1 1
* |________________________| | | |
*            |               | | |
*            v               v v v
*        (unused bits)       + - *
*/

#define OP_ADD (1 << 2)
#define OP_SUB (1 << 1)
#define OP_MUL (1 << 0)

bool check_in_range(const string& num, int k) {
    // check num <= 10^k

    if (k == 0) {
        // 10^0 = 1
        return num == "1";
    }

    if (static_cast<int>(num.size()) > k + 1) return false;
    if (static_cast<int>(num.size()) <= k) return true;

    // 200 > 10^2
    if (num[0] != '1') return false;

    return find_if(next(num.begin()), num.end(), [](char ch) -> bool {
        return ch != '0';
    }) == num.end();
}

int main(int argc, char* argv[]) {
	registerValidation(argc, argv);
	// about testlib, see https://codeforces.com/blog/entry/18426

	uint32_t allow_op_bit = atoi(argv[3]);
    vector<char> allow_ops;
    if (allow_op_bit & OP_ADD) allow_ops.emplace_back('+');
    if (allow_op_bit & OP_SUB) allow_ops.emplace_back('-');
    if (allow_op_bit & OP_MUL) allow_ops.emplace_back('*');

    int ab_upper = atoi(argv[1]);
    int c_upper = atoi(argv[2]);


    // a op b = c
    string a = inf.readToken();
    ensuref(check_in_range(a, ab_upper), "a should less than or equal to 10^%d", ab_upper);
    inf.readSpace();
    char op = inf.readChar();
    ensure(find(allow_ops.begin(), allow_ops.end(), op) != allow_ops.end());
    inf.readSpace();
    string b = inf.readToken();
    ensuref(check_in_range(b, ab_upper), "b should less than or equal to 10^%d", ab_upper);
    inf.readSpace();
    inf.readChar('=');
    inf.readSpace();
    string c = inf.readToken();
    ensuref(check_in_range(c, c_upper), "c should less than or equal to 10^%d", c_upper);
	inf.readEoln();
	inf.readEof();


	return 0;
}
