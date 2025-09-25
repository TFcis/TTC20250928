#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

#define ll long long
#define i64 long long
#define u32 unsigned int
#define u64 unsigned long long
#define u128 __uint128_t
#define i128 __int128
#define endl '\n'

using loli = int64_t;
using cute_loli = uint64_t;

template<typename T>
struct eval {
    using type = T;
    static const decltype(T::value) value = T::value;
};

template<typename T>
struct init {
    using type = typename eval<T>::type;
    static const decltype(type::value) value = type::value;
};

template<typename R>
struct Next {
    using type = typename eval<R>::type;
    static const decltype(type::value) value = type::value;
};

template<typename UIntType,
         UIntType seed = 1,
         UIntType a = 13857,
         UIntType c = 0,
         UIntType m = 2147483647>
struct my_linear_congruential_engine
{
    static const UIntType value = seed;
    static const UIntType maxvalue = m - 1;
};

template<typename UIntType, UIntType seed, UIntType a, UIntType c, UIntType m>
struct eval<my_linear_congruential_engine<UIntType, seed, a, c, m>>
{
    static const UIntType value = (a * seed + c) % m;
    using type = my_linear_congruential_engine<
        UIntType,
        (a * seed + c) % m,
        a,
        c,
        m
    >;
};

template<typename UIntType, UIntType seed, UIntType a, UIntType c, UIntType m>
struct init<my_linear_congruential_engine<UIntType, seed, a, c, m>>
{
    using type = typename eval<my_linear_congruential_engine<UIntType,seed,a,c,m>>::type;
    static const UIntType value = type::value;
};

template<typename Engine, loli Min, loli Max, loli val = 0>
struct UniformInt
{
    static const loli value = val;
};

template<typename Engine, loli Min, loli Max, loli val>
struct eval<UniformInt<Engine, Min, Max, val>>
{
    using tmptype = typename Next<Engine>::type;

    static_assert(Min <= Max, "UniformInt: Min must be <= Max");

    static const cute_loli rng_val_u64 = static_cast<cute_loli>(tmptype::value);
    static const cute_loli rng_max_plus1_u64 = static_cast<cute_loli>(tmptype::maxvalue) + 1ULL;

    static const i128 range_signed = static_cast<i128>(Max) - static_cast<i128>(Min) + 1;
    static_assert(range_signed > 0, "UniformInt: computed range must be positive");

    static const cute_loli mapped =
        static_cast<cute_loli>(
            ( static_cast<i128>(rng_val_u64) * range_signed ) /
            static_cast<i128>(rng_max_plus1_u64)
        );

    static const loli value =
        static_cast<loli>( static_cast<__int128>(Min) + static_cast<__int128>(mapped) );

    using type = UniformInt<tmptype, Min, Max, value>;
};

template<typename R, size_t I>
struct nth_next {
    using type = typename nth_next<typename Next<R>::type, I-1>::type;
};
template<typename R>
struct nth_next<R, 0> { using type = R; };

template<typename R, size_t... Is>
constexpr std::array<u64, sizeof...(Is)> make_pool(std::index_sequence<Is...>) {
    return { { (static_cast<u64>(nth_next<R, Is>::type::value))... } };
}

constexpr char inits[] = __TIME__;
constexpr int defaultseed = (inits[0]-'0')*100000+(inits[1]-'0')*10000 +
(inits[3]-'0')*1000+(inits[4]-'0')*100+
(inits[6]-'0')*10+inits[7]-'0';

using engine0 = my_linear_congruential_engine<uint64_t, defaultseed, 3227ULL, 1110ULL, 2147483647ULL>;
using RND = Next<UniformInt<engine0, 1000000000000000000LL, 2000000000000000000LL>>::type;
constexpr array<u64, 7> basenum{2ull, 325ull, 9375ull, 28178ull, 450775ull, 9780504ull, 1795265022ull};
constexpr std::array<u64, 150> rnd_pools = make_pool<RND>( std::make_index_sequence<150>{} );

// from wonderhoi
constexpr u64 fsp(u128 a, u64 b, const u64 mod) {
    u128 tmp = 1ull;
	a %= static_cast<u128>(mod);
	for(; b > 0; b >>= 1){
		if (b & 1){
			tmp *= a;
			tmp %= static_cast<u128>(mod);
		}
		a *= a;
		a %= static_cast<u128>(mod);
	}
	return static_cast<u64>(tmp % static_cast<u128>(mod));
}

// from wonderhoi
constexpr bool check64(u64 p) {
    if (p < 2) return 0;
	bool tmb = false;
	u64 exp = p - 1, tmp = 0;
	int num2 = 0;
	for (const auto i : basenum){
        if (i >= p) break;
		tmb = false;
		exp = p - 1;
		num2 = 0;
		for (; (exp & 1)^1; exp >>= 1) num2++;
		tmp = fsp(i, exp, p);
		if (tmp == 1 || tmp == p - 1) {
            tmb = true;
            continue;
        }
		for (int j = 1; j < num2; j++){
            tmp = tmp * tmp % p;
            if (tmp == p - 1) {
                tmb = true;
                break;
            }
		}
        if (!tmb) return false;
	}
	return true;
}

// from wonderhoi
constexpr i64 prime64(int pool_idx) {
    u64 p = 0;
    do {
        p = rnd_pools[pool_idx++] | 1ull;
   	} while(!check64(p));
	return static_cast<i64>(p);
}

u64 mul_mod(u64 a, u64 b, u64 mod) {
    return static_cast<u64>(static_cast<u128>(a) * static_cast<u128>(b) % mod);
}

u64 fastpow(u64 base, u64 exp, u64 mod) {
    u64 res = 1;
    u64 b = base % mod;
    while (exp) {
        if (exp & 1) res = mul_mod(res, b, mod);
        b = mul_mod(b, b, mod);
        exp >>= 1;
    }
    return res;
}

inline u64 str2u64(const string &s, size_t pos, size_t len) {
    u64 v = 0;
    for (size_t i = 0; i < len; ++i) {
        v = v * 10 + static_cast<u64>(s[pos + i] ^ '0');
    }
    return v;
}

u64 mod_from_str(const string &s, u64 m, int block_size = 18) {
    size_t n = s.size();
    if (n == 0) return 0;
    size_t f = n % block_size;
    if (f == 0) f = block_size;
    u64 r = str2u64(s, 0, f) % m;
    u64 base_full = fastpow(10 % m, static_cast<u64>(block_size), m);
    for (size_t pos = f; pos < n; pos += block_size) {
        size_t len = min(static_cast<size_t>(block_size), n - pos);
        u64 blk = str2u64(s, pos, len);
        r = (mul_mod(r, base_full, m) + blk % m) % m;
    }
    return r;
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

#define nitrogen std::ios::sync_with_stdio(false), std::cin.tie(nullptr)

int main() {
    nitrogen;

    const double epsilon = 1e-18;
    const int block_size = 9;
    array<i64, 1> primes64 = { prime64(0) };

    string A, B, C;
    char op, unused;
    cin >> A >> op >> B >> unused >> C;
    if (op == '*') {
        const int bits = 64;
        double need = ceil((-log2(epsilon)) / bits);
        int t = max(1, static_cast<int>(need));

        for (int i = 0; i < t; ++i) {
            u64 m = primes64[i % primes64.size()];
            u64 a_mod = mod_from_str(A, m, block_size);
            u64 b_mod = mod_from_str(B, m, block_size);
            u64 c_mod = mod_from_str(C, m, block_size);
            u64 p_mod = mul_mod(a_mod, b_mod, m);
            if (p_mod != c_mod) {
                cout << "No" << endl;
                return 0;
            }
        }

        cout << "Yes" << endl;
    } else if (op == '+') {
        cout << (add(A, B) == C ? "Yes" : "No") << endl;
    } else if (op == '-') {
        cout << (A == add(B, C) ? "Yes" : "No") << endl;
    }

    return 0;
}
