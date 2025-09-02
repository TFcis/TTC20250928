#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

// from tw87 TOJ 14 https://toj.tfcis.org/oj/chal/209777/
#define cd complex<double>
const double PI = acos(-1);
const int ten = 100;
const int dig = 2;
struct BIGINT{
    vector< int > num;
    explicit BIGINT(int n){
        while(n) num.push_back(n % ten), n /= ten;
    }
    explicit BIGINT(string n){
        reverse(n.begin(), n.end());
        n.resize((n.size() + dig - 1) / dig * dig, '0');
        for(int i = 0; i < static_cast<int>(n.size()); i += dig){
            int tmp = 0;
            for(int j = i + dig - 1; j >= i; --j){
                tmp *= 10;
                tmp += n[j] - '0';
            }
            num.push_back(tmp);
        }
    }
    void fix(){
        num.push_back(0);
        for(int i = 0; i < static_cast<int>(num.size()) - 1; ++i){
            num[i + 1] += num[i] / ten;
            num[i] %= ten;
        }
        while(static_cast<int>(num.size()) > 1 && num.back() == 0) num.pop_back();
    }
    void output(){
        cout << this->to_string() << "\n";
    }
    string to_string() {
        fix();
        string ans;
        for(int i : num){
            string tmp = ::to_string(i);
            reverse(tmp.begin(), tmp.end());
            tmp.resize(dig, '0');
            ans += tmp;
        }
        while(static_cast<int>(ans.size()) > 1 && ans.back() == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
    void fft(vector< cd > &a, bool inv = false){
        int n = static_cast<int>(a.size());
        for(int i = 0, j = 0; i < n; ++i){
            if(i < j) swap(a[i], a[j]);
            for(int k = n >> 1; (j ^= k) < k; k >>= 1);
        }
        for(int step = 1; step < n; step <<= 1){
            double theta = (inv ? 2 : -2) * PI / (step << 1);
            cd omega(cos(theta), sin(theta));
            for(int i = 0; i < n; i += step << 1){
                cd now(1, 0);
                for(int j = i; j < i + step; ++j){
                    cd x = a[j], y = a[j + step] * now;
                    a[j] = x + y;
                    a[j + step] = x - y;
                    now *= omega;
                }
            }
        }
        if(inv) for(int i = 0; i < n; ++i) a[i] /= n;
    }
    void mul(BIGINT &B){
        vector< cd > a(num.size()), b(B.num.size());
        for(int i = 0; i < static_cast<int>(a.size()); ++i) a[i] = num[i];
        for(int i = 0; i < static_cast<int>(b.size()); ++i) b[i] = B.num[i];
        int n = (2 << (__lg(a.size() + b.size())));
        a.resize(n);
        b.resize(n);
        num.resize(n);
        fft(a);
        fft(b);
        for(int i = 0; i < n; ++i) a[i] *= b[i];
        fft(a, 1);
        for(int i = 0; i < n; ++i) num[i] = static_cast<int>(round(a[i].real()));
        fix();
    }
    void add(BIGINT &x){
        auto &a = num;
        auto &b = x.num;
        int n = static_cast<int>(max(a.size(), b.size()));
        a.resize(n + 1, 0);
        b.resize(n + 1, 0);
        int carry = 0;
        for(int i = 0; i <= n; ++i){
            carry += b[i];
            a[i] += carry % ten;
            carry /= ten;
        }
        fix();
    }
    void sub(BIGINT &x){
        auto &a = num;
        auto &b = x.num;
        int n = static_cast<int>(max(a.size(), b.size()));
        a.resize(n + 1, 0);
        b.resize(n + 1, 0);
        for(int i = 0; i < n; ++i){
            a[i] += ten; a[i + 1] -= 1;
            a[i] -= b[i];
            if(a[i] >= ten){
                a[i + 1] += 1, a[i] -= ten;
            }
        }
    }
};

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

using loli = int64_t;
const loli base_digit = 8;

string gen_kdigit_random_bignum(int k) {
    static int kdigit_upper[] {-1, 9, 99, 999, 9999, 99999, 999999, 9999999, 99999999};
    static int kdigit_lower[] {-1, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
    string result;
    while (k > 0) {
        if (k >= 8) {
            result += to_string(rnd.next(kdigit_lower[base_digit], kdigit_upper[base_digit]));
        } else {
            result += to_string(rnd.next(kdigit_lower[k], kdigit_upper[k]));
        }
        k -= base_digit;
    }

    return result;
}

// from blameazu
string add(string a, string b) {
	string re;
	int tmp = 0;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	if(a.size() < b.size()) a.resize(b.size(), '0');
	if(a.size() > b.size()) b.resize(a.size(), '0');
	for(int i = 0; i < static_cast<int>(a.size()); i++) {
		re += static_cast<char>('0' + (a[i]-'0' + b[i]-'0'+tmp)%10);
		tmp = (a[i]+b[i]-'0'-'0'+tmp)/10;
	}
	if(tmp) re+=static_cast<char>('0'+tmp);
	reverse(re.begin(), re.end());
	return re;
}

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	// about testlib, see https://codeforces.com/blog/entry/18291

	uint32_t allow_op_bit = atoi(argv[3]);
    vector<char> allow_ops;
    if (allow_op_bit & OP_ADD) allow_ops.emplace_back('+');
    if (allow_op_bit & OP_SUB) allow_ops.emplace_back('-');
    if (allow_op_bit & OP_MUL) allow_ops.emplace_back('*');

    int ab_upper = atoi(argv[1]);
    int c_upper = atoi(argv[2]);


    char op = allow_ops[rnd.next(0, static_cast<int>(allow_ops.size() - 1))];
    bool ans_no = rnd.next(0, 1) == 0;

    string str_a, str_b, str_c;
    switch (op) {
    case '+': {
        BIGINT a = BIGINT(gen_kdigit_random_bignum(ab_upper));
        BIGINT b = BIGINT(gen_kdigit_random_bignum(ab_upper));
        BIGINT c = a;
        c.add(b);

        str_a = a.to_string();
        str_b = b.to_string();
        str_c = c.to_string();
        break;
    }
    case '-': {
        BIGINT a = BIGINT(gen_kdigit_random_bignum(ab_upper));
        BIGINT b = BIGINT(gen_kdigit_random_bignum(rnd.next(1, ab_upper - 1)));
        BIGINT c = a;
        c.sub(b);

        str_a = a.to_string();
        str_b = b.to_string();
        str_c = c.to_string();
        break;
    }
    case '*': {
        BIGINT a = BIGINT(gen_kdigit_random_bignum(ab_upper));
        BIGINT b = BIGINT(gen_kdigit_random_bignum(ab_upper));
        BIGINT c = a;
        c.mul(b);

        str_a = a.to_string();
        str_b = b.to_string();
        str_c = c.to_string();
        break;
    }
    default:
        assert(false && "unreachable");
    }

    if (ans_no) {
        vector<bool> vis(str_c.size(), false);

        int change_cnt = rnd.next(1, static_cast<int>(str_c.size()) / 2);
        while (change_cnt) {
            int idx = rnd.next(0, static_cast<int>(str_c.size()) - 1);
            if (vis[idx]) continue;
            str_c[idx] = static_cast<char>((((static_cast<int>(str_c[idx]) ^ 48) + 1) % 10) + 48);
            vis[idx] = true;
            change_cnt -= 1;
        }
    }

    cout << str_a << " " << op << " " << str_b << " = " << str_c << '\n';

	return 0;
}
