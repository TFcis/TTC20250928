#include<bits/stdc++.h>
#define int long long
#define all(v) v.begin(), v.end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
#define X first
#define Y second

using namespace std;
const int maxn = 2e5 + 10;
const int mod = 1e9 + 7;//    998244353;
const int llmx = 1e18;

#define cd complex<double>
const double PI = acos(-1);
const int ten = 100;
const int dig = 2;
struct BIGINT{
    vector< int > num;
    BIGINT(int n){
        while(n) num.push_back(n % ten), n /= ten;
    }
    BIGINT(string n){
        reverse(n.begin(), n.end());
        n.resize((n.size() + dig - 1) / dig * dig, '0');
        for(int i = 0; i < (int)n.size(); i += dig){
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
        for(int i = 0; i < (int)num.size() - 1; ++i){
            num[i + 1] += num[i] / ten;
            num[i] %= ten;
        }
        while((int)num.size() > 1 && num.back() == 0) num.pop_back();
    }
    void output(){
        fix();
        string ans;
        for(int i = 0; i < (int)num.size(); ++i){
            string tmp = ::to_string(num[i]);
            reverse(tmp.begin(), tmp.end());
            tmp.resize(dig, '0');
            ans += tmp;
        }
        while((int)ans.size() > 1 && ans.back() == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }
    void fft(vector< cd > &a, bool inv = 0){
        int n = a.size();
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
        for(int i = 0; i < (int)a.size(); ++i) a[i] = num[i];
        for(int i = 0; i < (int)b.size(); ++i) b[i] = B.num[i];
        int n = (2 << (__lg(a.size() + b.size())));
        a.resize(n);
        b.resize(n);
        num.resize(n);
        fft(a);
        fft(b);
        for(int i = 0; i < n; ++i) a[i] *= b[i];
        fft(a, 1);
        for(int i = 0; i < n; ++i) num[i] = (int) round(a[i].real());
        fix();
    }
    void add(BIGINT &x){
        auto &a = num;
        auto &b = x.num;
        int n = max(a.size(), b.size());
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
        int n = max(a.size(), b.size());
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
};
void sol(){
    string As, Bs, Cs;
    char op, unused;
    cin >> As >> op >> Bs >> unused >> Cs;
    BIGINT A(As), B(Bs), C(Cs);
    if (op == '*') {
        A.mul(B);
    } else if (op == '+') {
        A.add(B);
    } else if (op == '-') {
        A.sub(B);
    }
    cout << (A.to_string() == C.to_string() ? "Yes" : "No") << '\n';
	// if(op == "mul"){
	// 	BIGINT A(a), B(b);
	// 	A.mul(B);
	// 	A.output();
	// }
	// else{
	// 	BIGINT ans("1"), A(a);
	// 	int p = stoll(b);
	// 	while(p){
	// 		if(p & 1) ans.mul(A);
	// 		p >>= 1;
	// 		A.mul(A);
	// 	}
	// 	ans.output();
	// }
}
/*


*/
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cerr.tie(0);
    int t = 1; //cin >> t;
    while(t--) sol();
}
