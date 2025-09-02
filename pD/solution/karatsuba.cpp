#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace std;

// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
// #pragma GCC target("sse4,avx,avx2,abm,bmi,bmi2,adx,lzcnt,popcnt,tune=native")
// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,tune=native") // avx or sse
// #pragma pack(1) // 省記憶體用的

#ifdef TOBIICHI3227
#include <algo/debug.h>
#define debug(...) \
    cerr << "[" << __FUNCTION__ << "]L: " << __LINE__,\
    cerr << " (" << #__VA_ARGS__ << ") =", debug_out(__VA_ARGS__)
#else
#define debug(...) 3227
#endif

using loli = int64_t;
using pii = std::pair<int, int>;
using pll = std::pair<loli, loli>;
using bigloli = __int128;

template <typename T>
using order_multiset =
    __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less_equal<T>,
                     __gnu_pbds::rb_tree_tag,
                     __gnu_pbds::tree_order_statistics_node_update>;

template <typename T>
using order_set =
    __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>,
                     __gnu_pbds::rb_tree_tag,
                     __gnu_pbds::tree_order_statistics_node_update>;
#define pb push_back
#define eb emplace_back
#define ss second
#define ff first
#define dd cout << '\n';
#define all(container) (container).begin(), (container).end()
#define each(x, arr) for (auto &(x) : (arr))
#define c_each(x, arr) for (const auto &(x) : (arr))
#define F_OR(i, a, b, s) for (int (i) = (a); (s) > 0 ? (i) < (b) : (i) > (b); (i) += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define rep(...)       \
    F_ORC(__VA_ARGS__) \
    (__VA_ARGS__)
#define INF 0x3f
#define endl '\n'

template <typename T, typename U>
std::istream &operator>>(std::istream &is, std::pair<T, U> &val) {
    is >> val.first >> val.second;
    return is;
}
template <typename T>
std::istream &operator>>(std::istream &is, std::vector<T> &arr) {
    for (T &it : arr) {
        is >> it;
    }
    return is;
}

#if __cplusplus >= 201703L
template <typename... T> inline void ccin(T &...args) { ((std::cin >> args), ...); }
template <typename... T> inline void ccout(T &&...args) {
    ((std::cout << args), ...);
}
template <typename... T> inline void ccoutl(T &&...args) {
    ((std::cout << args), ...);
    std::cout << '\n';
}
#endif

#if __cplusplus <= 201402L
inline void ccin() {}
inline void ccout() {}
inline void ccoutl() { std::cout << "\n"; }

template <typename T, typename... Args> void ccin(T &first, Args &...args) {
    std::cin >> first;
    ccin(args...);
}

template <typename T, typename... Args> void ccout(T &&first, Args &&...args) {
    std::cout << first;
    ccout(args...);
}

template <typename T, typename... Args> void ccoutl(T &&first, Args &&...args) {
    std::cout << first;
    ccoutl(args...);
}
#endif

// from https://drawar.github.io/karatsuba-cpp/
string add(string lhs, string rhs) {
    int length = max(lhs.size(), rhs.size());
    int carry = 0;
    int sum_col;  // sum of two digits in the same column
    string result;

    // pad the shorter string with zeros
    while (lhs.size() < length)
      lhs.insert(0,"0");

    while (rhs.size() < length)
      rhs.insert(0,"0");

    // build result string from right to left
    for (int i = length-1; i >= 0; i--) {
      sum_col = (lhs[i]-'0') + (rhs[i]-'0') + carry;
      carry = sum_col/10;
      result.insert(0,to_string(sum_col % 10));
    }

    if (carry)
      result.insert(0,to_string(carry));

    // remove leading zeros
    return result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
}

string subtract(string lhs, string rhs) {
    int length = max(lhs.size(), rhs.size());
    int diff;
    string result;

    while (lhs.size() < length)
      lhs.insert(0,"0");

    while (rhs.size() < length)
      rhs.insert(0,"0");

    for (int i = length-1; i >= 0; i--) {
        diff = (lhs[i]-'0') - (rhs[i]-'0');
        if (diff >= 0)
            result.insert(0, to_string(diff));
        else {

            // borrow from the previous column
            int j = i - 1;
            while (j >= 0) {
                lhs[j] = ((lhs[j]-'0') - 1) % 10 + '0';
                if (lhs[j] != '9')
                    break;
                else
                    j--;
            }
            result.insert(0, to_string(diff+10));
        }

    }

    return result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
}

string multiply(string lhs, string rhs) {
    int length = max(lhs.size(), rhs.size());

    while (lhs.size() < length)
      lhs.insert(0,"0");

    while (rhs.size() < length)
      rhs.insert(0,"0");

    if (length == 1)
        return to_string((lhs[0]-'0')*(rhs[0]-'0'));

    string lhs0 = lhs.substr(0,length/2);
    string lhs1 = lhs.substr(length/2,length-length/2);
    string rhs0 = rhs.substr(0,length/2);
    string rhs1 = rhs.substr(length/2,length-length/2);

    string p0 = multiply(lhs0,rhs0);
    string p1 = multiply(lhs1,rhs1);
    string p2 = multiply(add(lhs0,lhs1),add(rhs0,rhs1));
    string p3 = subtract(p2,add(p0,p1));

    for (int i = 0; i < 2*(length-length/2); i++)
        p0.append("0");
    for (int i = 0; i < length-length/2; i++)
        p3.append("0");

    string result = add(add(p0,p1),p3);

    return result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
}

#define nitrogen std::ios::sync_with_stdio(false), std::cin.tie(nullptr)

const std::unordered_map<char, function<string(const string&, const string&)>> ops = {
{'*', [](const string& x, const string& y) -> string {
        return multiply(x, y);
    }},
{'+', [](const string& x, const string& y) -> string {
        return add(x, y);
    }},
{'-', [](const string& x, const string& y) -> string {
        return subtract(x, y);
    }},
};

int main() {
    nitrogen;

    string A, B, C;
    char op, unused;
    cin >> A >> op >> B >> unused >> C;
    cout << ((ops.find(op)->second(A, B) == C) ? "Yes" : "No") << endl;

    return 0;
}
