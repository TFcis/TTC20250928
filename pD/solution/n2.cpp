// from https://toj.tfcis.org/oj/chal/213696/
// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const long long e_1e9 = 1000000000;
using BIGNUM = vector<int64_t>;

BIGNUM multiply(const BIGNUM& a, const BIGNUM& b){
    BIGNUM result(0);
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            while(result.size() < i + j + 1) result.emplace_back(0);
            result[i + j] += a[i] * b[j];
            if(result[i + j] > e_1e9){
                if(result.size() < i + j + 2) result.emplace_back(0);
                result[i + j + 1] += result[i + j] / e_1e9;
                result[i + j] = result[i + j] % e_1e9;
            }
        }
    }
    while(result[result.size() - 1] >= e_1e9){
        result.emplace_back(result[result.size() - 1] / e_1e9);
        result[result.size() - 2] = result[result.size() - 2] % e_1e9;
    }
    return result;
}

BIGNUM big_num(const string& big_num){
    string big = big_num;
    BIGNUM result(0);
    while(big.size() > 0){
        if(big.size() >= 9){
            string small = big.substr(big.size() - 9);
            int ins = stoi(small);
            result.emplace_back((long long)ins);
            big.erase(big.size() - 9);
        }
        else{
            int ins = stoi(big);
            result.emplace_back((long long)ins);
            big.erase();
        }
    }
    return result;
}

string to_string(BIGNUM& num) {
    static const int pow_10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
    string result;
    while(num.size() > 1 && num[num.size() - 1] == 0) num.pop_back();

    for(int i = num.size() - 1; i >= 0 ; i--){
        if(i == num.size() - 1 || num[i] > pow_10[8]) result += to_string(num[i]);
        else{
            for(int j = 8; j > 0; j--){
                if(num[i] < pow_10[j]) result += '0';
                else break;
            }
            result += to_string(num[i]);
        }
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

int main() {
    string As, Bs, Cs;
    char op, unused;
    cin >> As >> op >> Bs >> unused >> Cs;

    if (op == '*') {
        BIGNUM a = big_num(As);
        BIGNUM b = big_num(Bs);
        BIGNUM p = multiply(a, b);

        cout << (to_string(p) == Cs ? "Yes" : "No") << '\n';
    } else if (op == '+') {
        cout << (add(As, Bs) == Cs ? "Yes" : "No") << '\n';
    } else if (op == '-') {
        cout << (As == add(Bs, Cs) ? "Yes" : "No") << '\n';
    }

    return 0;
}
