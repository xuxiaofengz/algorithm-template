//例题:洛谷 P1816 忠诚

template<typename T>
struct SortTable{
	vector<vector<T>> st;
	int s;
	SortTable(int n):st((int)log2(n)+1,vector<T>(n+1,0)),s(n){}
	void init(T *data)//data数据的起始位置为1;
	{
		for(int i=1;i<=s;i++)st[0][i]=data[i];
		for(int len=1;(1<<len)<=n;len++){
			for(int i=1;i<=(n-len+1);i++){
				st[len][i]=min(st[len-1][i],st[len-1][i+(1<<(len-1))]);
			}
		}
	}
	T get(int l,int r)
	{
		int x=log2(r-l+1);
		return min(st[x][l],st[x][r-(1<<x)+1]);
	}
};
