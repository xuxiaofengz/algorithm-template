//洛谷：P3368 【模板】树状数组 2
//区间修改，单点查询
//依赖于差分思想

int a[N];
int tr[N];

//区间修改[l,r]:add(l,val),add(r+1,-val)
void add(int ind,int val){
	while(ind<=n){
		tr[ind]+=val;
		ind+=ind&(-ind);
	}
}

//单点查询：a[i]+sum(i)
int sum(int ind){
	int res=0;
	while(ind){
		res+=tr[ind];
		ind-=ind&(-ind);
	}
	return res;
}
int sum(int l,int r){
	return sum(r)-sum(l-1);
}
