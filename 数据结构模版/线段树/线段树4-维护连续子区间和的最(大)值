//例题:洛谷 P4513 小白逛公园
//说明: 1.维护区间内连续子区间和的最大值(因为存在为负数的节点所以需要维护连续子区间和的最大值)
//      2.单点修改（非加减）

struct Tnode{//用于存储查询中的结果
	public:
	ll ans,maxl,maxr,sum;//ans:连续子区间的最大值;maxl(maxr):区间左(右)端点为起点的连续区间和的最大值;sum:区间和
	Tnode(){}
	Tnode(int a,int b,int c,int d):ans(a),maxl(b),maxr(c),sum(d){}
};
template<typename T>
struct segtree{
	T *data;
	vector<T> L,R,ans,maxl,maxr,sum;//ans:连续子区间的最大值;maxl(maxr):区间左(右)端点为起点的连续区间和的最大值;sum:区间和
	segtree(T si,T *data):L(4*si+1),R(4*si+1),ans(4*si+1),maxl(4*si+1),maxr(4*si+1),sum(4*si+1){
		this->data=data;
		init(1,1,si);
	}
	void update(T ind)//建树以及某一节点发生改变时，重新更新树的节点
	{
		int lc=ind*2,rc=ind*2+1;
		sum[ind]=sum[lc]+sum[rc];
		maxl[ind]=max(maxl[lc],sum[lc]+maxl[rc]);
		maxr[ind]=max(maxr[rc],sum[rc]+maxr[lc]);
		ans[ind]=max({sum[ind],ans[lc],ans[rc],maxr[lc]+maxl[rc]});
	}
	void update(Tnode &node,Tnode s1,Tnode s2)//用于请求时的结果的更新
	{
		node.sum=s1.sum+s2.sum;
		node.maxl=max(s1.maxl,s1.sum+s2.maxl);
		node.maxr=max(s2.maxr,s2.sum+s1.maxr);
		node.ans=max({node.sum,s1.ans,s2.ans,s1.maxr+s2.maxl});
	}
	void init(T ind,T l,T r)//建树
	{
		L[ind]=l;R[ind]=r;
		if(l==r){
			maxl[ind]=maxr[ind]=sum[ind]=ans[ind]=data[l];
			return;
		}
		int mid=l+(r-l)/2;
		init(ind*2,l,mid);
		init(ind*2+1,mid+1,r);
		update(ind);
	}
	
	Tnode query(T ind,T l,T r)//查询某区间的连续子区间和的最大值
	{
		if(L[ind]>r||R[ind]<l)return Tnode(-1e8,-1e8,-1e8,-1e8);
		
		if(L[ind]>=l&&R[ind]<=r)return Tnode(ans[ind],maxl[ind],maxr[ind],sum[ind]);
		int mid=L[ind]+(R[ind]-L[ind])/2;
		int lc=ind*2,rc=ind*2+1;
		if(r<=mid)return query(lc,l,r);//全在右区间
		else{
			if(mid<l)return query(rc,l,r);//全在左区间
			else{
				Tnode t,s1=query(lc,l,r),s2=query(rc,l,r);
				update(t,s1,s2);
				return t;
			}
		}
	}
	
	void add(T ind,T l,T r,T val)//更改某一叶子节点的值（非加减，直接更改）
	{
		if(L[ind]>r||R[ind]<l)return ;
		if(L[ind]>=l&&R[ind]<=r){
			maxl[ind]=maxr[ind]=sum[ind]=ans[ind]=val;
			return;
		}
		T le=ind*2,ri=ind*2+1;
		add(le,l,r,val);
		add(ri,l,r,val);
		update(ind);
	}
};
