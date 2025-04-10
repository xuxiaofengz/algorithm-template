//例题:洛谷p1908 逆序对
//     洛谷P2345 [USACO04OPEN] MooFest G

template<typename T>
struct tree{
	vector<T> lis;
	int len;
	tree(int le):lis(le),len(le){}
	
	void add(int ind,int val)
	{
		while(ind<=len){
			lis[ind]+=val;ind+=ind&-ind;
		}
	}
	T sum(int ind)
	{
		ll res=0;
		while(ind>0){
			res+=lis[ind];ind-=ind&-ind;
		}
		return res;
	}
	T sum(int l,int r)
	{
		if(l>r)return 0;
		return sum(r)-sum(l-1);
	}
};
