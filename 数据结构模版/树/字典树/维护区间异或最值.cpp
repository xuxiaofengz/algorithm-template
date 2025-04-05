//第十四届蓝桥杯大赛软件赛省赛C/C++ 大学 C 组 异或和之差

const int N=2e5+5;
int n,m,k;
int a[N];
int ltr[1<<21][2],rtr[1<<21][2];
int lmax[N],lmin[N],rmax[N],rmin[N];
int ls[N],rs[N];
int ind=1;
//添加元素
void add(int x,int tr[][2])
{
	int p=0;
	for(int i=20;i>=0;i--){
		int bit=(x>>i)&1;
		if(!tr[p][bit]){//careful
			tr[p][bit]=ind++;
		}
		p=tr[p][bit];
	}
}
//查询以元素x结尾该数组区间异或的最大值
int queryMax(int x,int tr[][2])
{
	int res=0,p=0;
	for(int i=20;i>=0;i--){
		int bit=(x>>i)&1;
		if(tr[p][!bit]){
			res+=(1<<i);
			p=tr[p][!bit];
		}
		else{
			p=tr[p][bit];
		}
	}
	return res;
}
//查询以元素x结尾该数组区间异或的最小值
int queryMin(int x,int tr[][2])
{
	int res=0,p=0;
	for(int i=20;i>=0;i--){
		int bit=(x>>i)&1;
		if(tr[p][bit]){
			p=tr[p][bit];
		}
		else{
			p=tr[p][!bit];
			res+=(1<<i);
		}
	}
	return res;
}

void solve()
{
	for(int i=0;i<=n+1;i++){
		lmin[i]=rmin[i]=1e9;
	}
	add(0,ltr);//便于处理一个数本身就是最值
	for(int i=1;i<=n;i++){
		ls[i]=ls[i-1]^a[i];//前缀异或
		lmin[i]=min(lmin[i-1],queryMin(ls[i],ltr));
		lmax[i]=max(lmax[i-1],queryMax(ls[i],ltr));
		add(ls[i],ltr);
	}
	ind=1;
	add(0,rtr);
	for(int i=n;i>=1;i--){
		rs[i]=rs[i+1]^a[i];
		rmin[i]=min(rmin[i+1],queryMin(rs[i],rtr));
		rmax[i]=max(rmax[i+1],queryMax(rs[i],rtr));
		add(rs[i],rtr);
	}
	int res=0;
	for(int i=1;i<n;i++){
		res=max({res,lmax[i]-rmin[i+1],rmax[i+1]-lmin[i]});//不相交区间异或和的差值的最值
	}
	cout<<res;
}
