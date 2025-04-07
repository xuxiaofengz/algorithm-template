//例题：P3372 【模板】线段树 1
//区间和以及区间更新（带懒标记）

template<typename T>
struct segtree{
	vector<T> tr;
	T *data;
	vector<T> L,R,lazy;
	segtree(T si,T *data):tr(si*4+1),lazy(4*si+1),L(si*4+1),R(si*4+1){
		this->data=data;
	}
	void init(T ind,T l,T r)
	{
		L[ind]=l;R[ind]=r;
		if(l==r){
			tr[ind]=data[l];
			return;
		}
		int mid=l+(r-l)/2;
		init(ind*2,l,mid);
		init(ind*2+1,mid+1,r);
		tr[ind]=tr[ind*2]+tr[ind*2+1];
	}
	
	T query(T ind,T l,T r)
	{
		if(L[ind]>r||R[ind]<l)return 0;
		
		if(L[ind]>=l&&R[ind]<=r)return tr[ind];
		if(lazy[ind]>0){
			pushdown(ind);
		}
		T s1=query(ind*2,l,r);
		T s2=query(ind*2+1,l,r);
		return s1+s2;
	}
	
	void add(T ind,T l,T r,T val)
	{
		if(L[ind]>r||R[ind]<l)return ;
		if(L[ind]>=l&&R[ind]<=r){
			tr[ind]+=val*(R[ind]-L[ind]+1);
			lazy[ind]+=val;
			return;
		}
		T le=ind*2,ri=ind*2+1;
		if(lazy[ind]!=0)pushdown(ind);
		add(le,l,r,val);
		add(ri,l,r,val);
		tr[ind]=tr[le]+tr[ri];
	}
	
	void pushdown(T ind)
	{
		T le=ind*2,ri=ind*2+1;
		lazy[le]+=lazy[ind];lazy[ri]+=lazy[ind];
		tr[le]+=(ll)lazy[ind]*(R[le]-L[le]+1);
		tr[ri]+=(ll)lazy[ind]*(R[ri]-L[ri]+1);
		lazy[ind]=0;
	}
};
