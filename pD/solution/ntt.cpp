#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=2000000;
inline void myassert(bool x) {if(!x) assert(0);}

// from https://toj.tfcis.org/oj/chal/20205/
class NTT
{
    private:
    LL epsilon[maxn],buffer[maxn];
    static const LL P=(7LL<<50)+1;
    static const LL G=6;
    inline LL add(const LL& a,const LL b)
    {
        if(a+b>P) return a+b-P;
        else if(a+b<0) return a+b+P;
        return a+b;
    }
    inline LL mul(const LL& a,const LL b)
    {
        LL y=(LL)((double)a*b/P+0.5);
        LL r=(a*b-y*P)%P;
        return r<0?r+P:r;
    }
    LL fast_pow(LL x,LL a)
    {
        LL res=1;
        for(;a;a>>=1,x=mul(x,x)) if(a&1) res=mul(res,x);
        return res;
    }
    inline void init(LL n)
    {
        epsilon[0]=1;
        epsilon[1]=fast_pow(G,(P-1)/n);
        for(LL i=2;i<n;i++) epsilon[i]= mul(epsilon[1],epsilon[i-1]);
    }
    void fft(LL n,LL offset,LL step)
    {
        for(LL i=0,j=0;i<n;i++)
        {
            if(i>j) swap(buffer[i],buffer[j]);
            for(LL k=n>>1;(j^=k)<k;k>>=1);
        }
        for(LL i=2,m=1;i<=n;i<<=1,m<<=1)
            for(LL offset=0;offset<n;offset+=i)
                for(LL k=0;k<m;k++)
                {
                    LL rgt= mul(epsilon[n / i * k ] , buffer[offset + m + k ]);
                    buffer[offset + m + k] = add(buffer[offset + k], -rgt);
                    buffer[offset + k] = add(buffer[offset + k] , rgt);
                    myassert(buffer[offset+m+k]>=0 && buffer[offset+k]>=0);
                }
    }

    public:
    void dft(const vector<LL>& coef,LL n,vector<LL>& pv)
    {
        for(LL i=0;i<n;i++) buffer[i]= (i<(int)coef.size()?coef[i]:0);
        fft(n,0,1);

        pv.resize(n);
        for(LL i=0;i<n;i++) pv[i]=buffer[i];
    }
    void idft(const vector<LL>& pv,LL n,vector<LL>& coef)
    {
        for(LL i=0;i<n;i++) buffer[i]= (i<(int)pv.size()?pv[i]:0);
        fft(n,0,1);

        coef.resize(n);
        LL inv=fast_pow(n,P-2);
        coef[0]=mul(buffer[0],inv);
        for(LL i=1;i<n;i++) coef[i]=mul(buffer[n-i],inv);
    }
    void conv(const vector<LL>& fx,const vector<LL>& gx,vector<LL>& hx)
    {
        LL n;
        for(n=1;n<(int)fx.size()+(int)gx.size();n<<=1);

        myassert(n<maxn);

        vector<LL> pv[3];
        init(n);
        dft(fx,n,pv[0]);
        dft(gx,n,pv[1]);

        pv[2].resize(n);
        for(LL i=0;i<n;i++) pv[2][i]=mul(pv[0][i],pv[1][i]);

        idft(pv[2],n,hx);
    }
}ntt;

char buffer[15000000];
class Bignum
{
    private:
    static const LL base=1000000;
    static const LL digit_base=6;
    vector<LL> num;
    inline void carry()
    {
        for(LL i=0;i<(int)num.size();i++) if(num[i]>=base)
        {
            if(i+1==num.size()) num.push_back(0);
            num[i+1]+=num[i]/base;
            num[i]%=base;
        }
        while(num.size()>1 && num[num.size()-1]==0) num.pop_back();
    }

    public:
    Bignum operator *(const Bignum& rhs) const
    {
        Bignum res;
        ntt.conv(num,rhs.num,res.num);
        res.carry();
        return res;
    }
    Bignum(const char* s)
    {
        LL n=strlen(s),val=0;
        for(LL i=n-1;i>=0;i-=digit_base)
        {
            val=0;
            for(LL j=max(0LL,i-digit_base+1);j<=i;j++) val=val*10+(s[j]-'0');
            num.push_back(val);
        }
        carry();
    }
    void show()
    {
        for(LL i=num.size()-1;i>=0;i--)
            if(i==num.size()-1) printf("%lld",num[i]);
            else printf("%06lld", num[i]);
        puts("");
    }
    string to_string() {
        int j = 0;
        for (LL i=num.size()-1;i>=0;i--) {
            if(i==num.size()-1) j += sprintf(buffer + j, "%lld",num[i]);
            else j += sprintf(buffer + j, "%06lld", num[i]);
        }
        string s(buffer);
        return s;
    }
    Bignum(LL x) {num.push_back(x);carry();}
    Bignum() {}
    ~Bignum() {vector<LL> ().swap(num);}
};

// from blameazu
string add(string a, string b) {
	string re;
	int tmp = 0;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	if(a.size() < b.size()) a.resize(b.size(), '0');
	if(a.size() > b.size()) b.resize(a.size(), '0');
	for(int i = 0; i < a.size(); i++) {
		re += char('0' + (a[i]-'0' + b[i]-'0'+tmp)%10);
		tmp = (a[i]+b[i]-'0'-'0'+tmp)/10;
	}
	if(tmp) re+=char('0'+tmp);
	reverse(re.begin(), re.end());
	return re;
}

int main() {
    string As, Bs, Cs;
    char op, unused;
    cin >> As >> op >> Bs >> unused >> Cs;
    if (op == '*') {
        Bignum A(As.c_str());
        Bignum B(Bs.c_str());
        cout << ((A*B).to_string() == Cs ? "Yes" : "No") << endl;
    } else if (op == '+') {
        cout << (add(As, Bs) == Cs ? "Yes" : "No") << endl;
    } else if (op == '-') {
        cout << (As == add(Bs, Cs) ? "Yes" : "No") << endl;
    }
}

