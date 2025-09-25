#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define u64 unsigned long long
#define u128 __uint128_t

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
	if(a.size() < b.size()) return "error";
	if(a.size() == b.size() && a < b) return "error";
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for(int i = 0; i < b.size(); i++){
		tmp = more_minus + a[i] - '0' - (b[i] - '0');
		more_minus = -(tmp<0);
		a[i] = (tmp+10)%10 + '0';
	}
	for(int i = b.size(); i < a.size(); i++){
		tmp = more_minus + a[i] - '0';
		more_minus = -(tmp<0);
		a[i] = (tmp+10)%10 + '0';
	}
	while(a.back() == '0') a.pop_back();
	if(a.empty()) a = "0";
	reverse(a.begin(),a.end());
	return a;
}

int bigmod(string& num, int p){
	int sum = 0;
	for(auto& i:num){
		sum = (sum<<3) + (sum<<1);
		sum += i - '0';
		sum %= p;
	}
	return sum;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	i64 prime;
	string a,b,op,c,t;
	cin>>a>>op>>b>>t>>c;
	string aaa,bbb,ccc;
	aaa=a;
	bbb=b;
	ccc=c;
	if(op == "*"){
		long long aa, bb, cc;
		do{
			aa = 0;
			for(auto& i:a) {
				aa += i - '0';
			}
			a = to_string(aa);
		}while(aa>=10);
		do{
			bb= 0;
			for(auto& i:b) {
				bb += i - '0';
			}
			b = to_string(bb);
		}while(bb>=10);
		do{
			cc = 0;
			for(auto& i:c) {
				cc += i - '0';
			}
			c = to_string(cc);
		}while(cc>=10);
		string aaaa = to_string(aa);
		aa *= bb;
		a = to_string(aa);
		do{
			aa = 0;
			for(auto& i:a) {
				aa += i - '0';
			}
			a = to_string(aa);
		}while(aa>=10);
		if(bigmod(aaa,11)*bigmod(bbb,11)%11 != bigmod(ccc,11)) cout << "No\n";
		else if(aa==cc) cout<<"Yes\n";
		else cout<<"No\n";
	}else if(op == "+"){
		if(bigadd(a,b) != c) cout<<"No\n";
		else cout<<"Yes\n";
	}else{
		if(bigminus(a,b) != c) cout<<"No\n";
		else cout<<"Yes\n";
	}
	return 0;
} //.
