//洛谷：P3811 【模板】模意义下的乘法逆元

ll inv[N];
ll n,mod;

//费马小定理
ll qpow(ll x,ll b)
{
	ll res=1;
	while(b){
		if(b&1)res=(res*x)%mod;
		x=(x*x)%mod;
		b>>=1;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>mod;
	inv[1]=1;
	cout<<inv[1]<<"\n";
  //线性推
	for(int i=2;i<=n;i++){
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
		cout<<inv[i]<<"\n";
	}
	
	return 0;
}
