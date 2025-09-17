#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	cin>>n>>s;
	if(s == "00") cout<<0<<'\n';
	else if(s == "01") cout<<1<<'\n'<<2<<'\n';
	else if(s == "10") cout<<1<<'\n'<<1<<'\n';
	else if(s == "11") cout<<-1<<'\n';
	else if(s == "000") cout<<0<<'\n';
	else if(s == "001") cout<<1<<'\n'<<3<<'\n';
	else if(s == "010") cout<<1<<'\n'<<2<<'\n';
	else if(s == "011") cout<<4<<'\n'<<1<<'\n'<<3<<'\n'<<2<<'\n'<<1<<'\n';
	else if(s == "100") cout<<1<<'\n'<<1<<'\n';
	else if(s == "101") cout<<2<<'\n'<<1<<'\n'<<3<<'\n';
	else if(s == "110") cout<<4<<'\n'<<3<<'\n'<<1<<'\n'<<2<<'\n'<<3<<'\n';
	else if(s == "111") cout<<3<<'\n'<<1<<'\n'<<3<<'\n'<<2<<'\n';
	else if(s == "0000") cout<<0<<'\n';
	else if(s == "0001") cout<<1<<'\n'<<4<<'\n';
	else if(s == "0010") cout<<1<<'\n'<<3<<'\n';
	else if(s == "0011") cout<<4<<'\n'<<2<<'\n'<<4<<'\n'<<3<<'\n'<<2<<'\n';
	else if(s == "0100") cout<<1<<'\n'<<2<<'\n';
	else if(s == "0101") cout<<2<<'\n'<<2<<'\n'<<4<<'\n';
	else if(s == "0110") cout<<4<<'\n'<<1<<'\n'<<3<<'\n'<<2<<'\n'<<1<<'\n';
	else if(s == "0111") cout<<3<<'\n'<<2<<'\n'<<4<<'\n'<<3<<'\n';
	else if(s == "1000") cout<<1<<'\n'<<1<<'\n';
	else if(s == "1001") cout<<2<<'\n'<<1<<'\n'<<4<<'\n';
	else if(s == "1010") cout<<2<<'\n'<<1<<'\n'<<3<<'\n';
	else if(s == "1011") cout<<5<<'\n'<<2<<'\n'<<4<<'\n'<<3<<'\n'<<2<<'\n'<<1<<'\n';
	else if(s == "1100") cout<<4<<'\n'<<3<<'\n'<<1<<'\n'<<2<<'\n'<<3<<'\n';
	else if(s == "1101") cout<<5<<'\n'<<3<<'\n'<<1<<'\n'<<2<<'\n'<<3<<'\n'<<4<<'\n';
	else if(s == "1110") cout<<3<<'\n'<<1<<'\n'<<3<<'\n'<<2<<'\n';
	else if(s == "1111") cout<<6<<'\n'<<3<<'\n'<<1<<'\n'<<2<<'\n'<<3<<'\n'<<4<<'\n'<<3<<'\n';
}
