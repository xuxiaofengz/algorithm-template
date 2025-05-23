实例：洛谷 p1714 切蛋糕（线段树或st维护区间最值）
ll pre[N];//维护的前缀和，也可以不是前缀和

struct segtree{
	ll tree[N*4],L[N*4],R[N*4];
	
	void build(int i,int l,int r)
	{
		L[i]=l;R[i]=r;
		if(l==r){
			tree[i]=pre[l];
			return;
		}
		ll mid=l+(r-l)/2;
		build(i<<1,l,mid);
		build((i<<1)+1,mid+1,r);
		tree[i]=min(tree[i<<1],tree[(i<<1)+1]);
	}
	ll query(int i,int l,int r)
	{
		ll cl=L[i],cr=R[i];
		if(l>cr||r<cl)return (ll)1e15;
		if(l<=cl&&r>=cr){
			return tree[i];
		}
		ll mid=l+(r-l)/2;
		ll t1,t2;
		t1=query(i<<1,l,r);
		t2=query((i<<1)+1,l,r);
		
		return min(t1,t2);
	}
}tr;
