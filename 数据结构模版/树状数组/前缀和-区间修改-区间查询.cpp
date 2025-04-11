//acwing:243. 一个简单的整数问题2

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod=1e9+7;

const int N=1e5+5;
int n,m;
int a[N];//原数据
ll sum[N];//原数据前缀和
ll d0[N],d1[N];//d0:d[i]差分前缀和,d1:d[i]*i差分前缀和
//单点更新
void add(ll d[],int ind,int val){
	for(;ind<=n;ind+=(ind&(-ind))){
		d[ind]+=val;
	}
}
//区间更新
void add(ll s0[],ll s1[],int l,int r,int val){
	add(s0,l,val);
	add(s0,r+1,-val);
	add(s1,l,l*val);
	add(s1,r+1,-(r+1)*val);
}
//前缀和查询
ll query(ll d[],int ind){
	ll res=0;
	for(;ind>=1;ind-=ind&-ind){
		res+=d[ind];
	}
	return res;
}
//区间查询
ll query(ll s0[],ll s1[],int l,int r){
	ll res=0;
	res=sum[r]+(ll)(r+1)*query(s0,r)-query(s1,r);//公式 sum[l,r]=sum[r]+(r+1)*d0[r]-d1[r]-(sum[l-1]+l*d0[l-1]-d1[l-1]);
	res-=sum[l-1]+(ll)l*query(s0,l-1)-query(s1,l-1);
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=a[i]+sum[i-1];
	}
	
	while(m--){
		int l,r,val;
		char op;
		cin>>op;
		if(op=='C'){
			cin>>l>>r>>val;
			add(d0,d1,l,r,val);
		}else{
			cin>>l>>r;
			ll res=query(d0,d1,l,r);
			cout<<res<<"\n";
		}
	}
	
	return 0;
}

