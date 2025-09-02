#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define u64 unsigned long long
#define u128 __uint128_t
#define ena ios::sync_with_stdio(0);cin.tie(0);
 
i64 prime64(){
	random_device rd;  
    mt19937_64 gen(rd());
    u64 l = 1000000000000000000ull, r = 2000000000000000000ull, p; // 1e18, 2e18
    uniform_int_distribution<u64> dist(l, r);
    vector<u64> basenum{2ull, 325ull, 9375ull, 28178ull, 450775ull, 9780504ull, 1795265022ull};
    function<bool(u64)> check64 = [&basenum](u64 p){
    	bool b = 0, tmb;
    	u64 exp, tmp;
    	int num2;
    	function<u64(u128, u64, const u64&)> fsp = [](u128 a, u64 b, const u64& mod){
    		u128 tmp = 1ull;
	    	a%=(u128)mod;
			for(;b>0;b>>=1){
				if(b&1){
					tmp*=a;
					tmp%=(u128)mod;
				}
				a*=a;
				a%=(u128)mod;
			}
			return (u64)(tmp%(u128)mod);
	    };
    	for(auto& i:basenum){
    		tmb = 1;
    		exp = p-1;
    		num2 = 0;
    		for(; (exp&1)^1 ; exp>>=1) num2++;
    		tmp = fsp(i,exp,p);
    		if(tmp==1||tmp==p-1) continue;
    		for(int i=0;i<num2;i++){
    			if(fsp(tmp,2,p)==p-1){
    				tmb = 0;
    				break;
    			}
    			tmp = tmp*tmp%p;
    		}
    		b|=tmb;
    	}
    	return b;
    };
    do{
		p = dist(gen)|1ull;
   	}while(check64(p));
	return p;
}

u128 bigmod(string& num, u128 p){
	u128 sum = 0;
	for(auto& i:num){
		sum = (sum<<3) + (sum<<1);
		sum += i - '0';
		sum %= p;
	}
	return sum;
}

string bigadd(string a, string b){
	int more_add = 0, tmp;
	if(a.size() < b.size()) swap(a,b);
	reverse(a.begin(),a.end());
	a+='0';
	reverse(b.begin(),b.end());
	for(int i = 0; i < b.size(); i++){
		tmp = more_add + a[i] - '0' + b[i] - '0';
		more_add = tmp/10;
		a[i] = tmp%10 + '0';
	}
	for(int i = b.size(); i < a.size(); i++){
		tmp = more_add + a[i] - '0';
		more_add = tmp/10;
		a[i] = tmp%10 + '0';
	}
	while(a.back() == '0') a.pop_back();
	reverse(a.begin(),a.end());
	return a;
}

string bigminus(string a, string b){
	int more_minus = 0, tmp;
	if(a.size() < b.size()){
		return "haha";
	}
	if(a.size() == b.size() && a < b){
		return "haha";
	}
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for(int i = 0; i < b.size(); i++){
		tmp = more_minus + a[i] - '0' - b[i] + '0';
		more_minus = -(tmp<0);
		a[i] = (tmp+10)%10 + '0';
	}
	for(int i = b.size(); i < a.size(); i++){
		tmp = more_minus + a[i] - '0';
		more_minus = -(tmp<0);
		a[i] = (tmp+10)%10 + '0';
	}
	while(a.back() == '0') a.pop_back();
	if(a.empty()) a ="0";
	reverse(a.begin(),a.end());
	return a;
}

int main(){
	ena;
	i64 prime;
	string a,b,op,c;
	cin>>a>>op>>b>>c;
	if(op == "*"){
		for(int i=0;i<3;i++){
			prime = prime64();
			if(bigmod(a,prime) * bigmod(b,prime) % prime != bigmod(c,prime)){
				cout<<"No\n";
				return 0;
			}
		}
		cout<<"Yes\n";
	}else if(op == "+"){
		if(bigadd(a,b) != c){
			cout<<"No\n";
		}else cout<<"Yes\n";
	}else{
		if(bigminus(a,b) != c){
			cout<<"No\n";
		}else cout<<"Yes\n";
	}
	return 0;
}
