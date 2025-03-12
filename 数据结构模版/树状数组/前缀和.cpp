//例题：洛谷p1908 逆序对

ll tr[N];
int cnt;

void add(int i,int val)
{
	while(i<=cnt){
//		cout<<i<<endl;
		tr[i]+=val;
		i+=i&-i;
	}
}
ll query(int i)
{
	ll res=0;
	while(i>0){
//		cout<<i<<endl;
		res+=tr[i];
		i-=i&-i;
	}
	return res;
}
