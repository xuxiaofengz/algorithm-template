//线段树1
/*
具体题目：洛谷 p1884
L[i]:节点i的左边界，R[i]:节点i的右边界
vis[i]:判断节点i的所属区域是否全部被包含 vis[i]大于0说明该区间的所有叶节点都是1（因为该线段树中，每一个叶节点的值要么为1，要么为 0）
v[i]:该节点所属区域中的和；
*/
template<typename T>
struct segtr{
	T L[N],R[N],vis[N],v[N];
	void init(int ind,int l,int r)
	{
		L[ind]=l;R[ind]=r;
		if(l==r)return;
		int mid=l+(r-l)/2;
		init(ind<<1,l,mid);
		init((ind<<1)+1,mid+1,r);
	}
	
	void add(int ind,int l,int r,int val)
	{
		if(L[ind]>r||R[ind]<l)return;
		if(l<=L[ind]&&r>=R[ind])vis[ind]+=val;
		else{
			add(ind<<1,l,r,val);
			add((ind<<1)+1,l,r,val);
		}	
		if(vis[ind]){
      //ys是被压缩后的y轴坐标（离散化）
			v[ind]=ys[R[ind]+1]-ys[L[ind]];
		}
		else{
			v[ind]=v[ind<<1]+v[(ind<<1)+1];
		}
	}
};
