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

#define nitrogen std::ios::sync_with_stdio(false), std::cin.tie(nullptr)

const std::unordered_map<char, function<loli(loli, loli)>> ops = {
{'+', [](loli x, loli y) -> loli {
        return x + y;
    }},
{'-', [](loli x, loli y) -> loli {
        return x - y;
    }},
};

int main() {
    nitrogen;

    loli a, b;
    char op, unused;
    cin >> a >> op >> b >> unused;

    if (auto iter = ops.find(op); iter != ops.end()) {
        loli c;
        cin >> c;
        cout << (iter->second(a, b) == c ? "Yes" : "No") << endl;
    } else {
        string c;
        cin >> c;

        bigloli p = static_cast<bigloli>(a) * static_cast<bigloli>(b);
        size_t i = c.size() - 1;

        while (p && i >= 0) {
            if ((c[i--] ^ 48) != p % 10) {
                cout << "No" << endl;
                return 0;
            }
            p /= 10;
        }
        cout << "Yes" << endl;
    }

    return 0;
}
